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