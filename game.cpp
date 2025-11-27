#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <utility>
using namespace std;

Game::Game(int size, string gameMode) : gridSize(size), score(0), mode(gameMode) {
    if (mode == "moves") {
        movesLeft = 20;
        timeLeft = -1;
    }
    else {
        movesLeft = -1;
        timeLeft = 60;
    }
    initializeGrid();
}
void Game::initializeGrid() {
    grid.resize(gridSize, vector<Tile>(gridSize));
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
vector<pair<int, int>> Game::findMatches() {
    vector<pair<int, int>> matches;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize - 2; j++) {
            if (grid[i][j].color == grid[i][j + 1].color &&
                grid[i][j].color == grid[i][j + 2].color) {
                matches.push_back({ i, j });
                matches.push_back({ i, j + 1 });
                matches.push_back({ i, j + 2 });
            }
        }
    }

    for (int i = 0; i < gridSize - 2; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (grid[i][j].color == grid[i + 1][j].color &&
                grid[i][j].color == grid[i + 2][j].color) {
                matches.push_back({ i, j });
                matches.push_back({ i + 1, j });
                matches.push_back({ i + 2, j });
            }
        }
    }

    sort(matches.begin(), matches.end());
    matches.erase(unique(matches.begin(), matches.end()), matches.end());

    return matches;
}
void Game::removeMatches() {
    auto matches = findMatches();
    if (matches.empty()) return;

    for (auto& match : matches) {
        grid[match.first][match.second].color = -1;
    }

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
        cout << "Можно менять только соседние плитки!" << endl;
        return;
    }

    swap(grid[row1][col1].color, grid[row2][col2].color);

    if (findMatches().empty()) {
        swap(grid[row1][col1].color, grid[row2][col2].color);
        cout << "Не образуется совпадений! Ход отменен." << endl;
    }
    else {
        if (mode == "moves") {
            movesLeft--;
        }
        removeMatches();
        while (!findMatches().empty()) {
            removeMatches();
        }
    }
}
void Game::display() {
    cout << "\nТекущий счет: " << score << endl;

    if (mode == "moves") {
        cout << "Осталось ходов: " << movesLeft << endl;
    }
    else {
        cout << "Осталось времени: " << timeLeft << " сек" << endl;
    }

    cout << "\n  ";
    for (int j = 0; j < gridSize; j++) {
        cout << j << " ";
    }
    cout << endl;

    for (int i = 0; i < gridSize; i++) {
        cout << i << " ";
        for (int j = 0; j < gridSize; j++) {
            cout << colors[grid[i][j].color] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
