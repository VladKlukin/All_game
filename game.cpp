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