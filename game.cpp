#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <utility>

Game::Game(int size, std::string gameMode) : gridSize(size), score(0), mode(gameMode) {
    if (mode == "moves") {
        movesLeft = 20;
        timeLeft = -1;
    } else {
        movesLeft = -1;
        timeLeft = 60;
    }
    initializeGrid();
}
void Game::initializeGrid() {//иницилизация поля
    grid.resize(gridSize, std::vector<Tile>(gridSize));
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = Tile(rand() % colors.size());
        }
    }
    ensureNoMatches();
}
void Game::ensureNoMatches() {
    while (findMatches().size() > 0) {
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                grid[i][j] = Tile(rand() % colors.size());
            }
        }
    }
}

std::vector<std::pair<int, int>> Game::findMatches() {
    std::vector<std::pair<int, int>> matches;
    
    // Check horizontal matches
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize - 2; j++) {
            if (grid[i][j].color == grid[i][j + 1].color && 
                grid[i][j].color == grid[i][j + 2].color) {
                matches.push_back({i, j});
                matches.push_back({i, j + 1});
                matches.push_back({i, j + 2});
            }
        }
    }
    
    // Check vertical matches
    for (int i = 0; i < gridSize - 2; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (grid[i][j].color == grid[i + 1][j].color && 
                grid[i][j].color == grid[i + 2][j].color) {
                matches.push_back({i, j});
                matches.push_back({i + 1, j});
                matches.push_back({i + 2, j});
            }
        }
    }
    
    // Remove duplicates
    std::sort(matches.begin(), matches.end());
    matches.erase(std::unique(matches.begin(), matches.end()), matches.end());
    
    return matches;
}
void Game::removeMatches() {
    auto matches = findMatches();
    if (matches.empty()) return;
    
    // Mark matched tiles for removal
    for (auto& match : matches) {
        grid[match.first][match.second].color = -1;
    }
    
    // Apply gravity
    for (int j = 0; j < gridSize; j++) {
        int writeIndex = gridSize - 1;
        for (int i = gridSize - 1; i >= 0; i--) {
            if (grid[i][j].color != -1) {
                grid[writeIndex][j].color = grid[i][j].color;
                writeIndex--;
            }
        }
        for (int i = writeIndex; i >= 0; i--) {
            grid[i][j].color = rand() % colors.size();
        }
    }
    
    score += matches.size() * 10;
}
void Game::swapTiles(int row1, int col1, int row2, int col2) {
    if (abs(row1 - row2) + abs(col1 - col2) != 1) {
        std::cout << "Можно менять только соседние плитки!" << std::endl;
        return;
    }
    
    std::swap(grid[row1][col1].color, grid[row2][col2].color);
    
    if (findMatches().empty()) {
        // No matches, swap back
        std::swap(grid[row1][col1].color, grid[row2][col2].color);
        std::cout << "Не образуется совпадений! Ход отменен." << std::endl;
    } else {
        if (mode == "moves") {
            movesLeft--;
        }
        removeMatches();
        while (!findMatches().empty()) {
            removeMatches();
        }
    }
}