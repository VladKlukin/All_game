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