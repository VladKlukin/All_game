#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"
#include "ui.h"
using namespace std;

void playTimeMode() {
    int gridSize = 8;
    Game game(gridSize, "time");
    time_t startTime = time(0);
    const int totalTime = 60;

    cout << "=== РЕЖИМ НА ВРЕМЯ ===" << endl;
    cout << "У вас " << totalTime << " секунд!" << endl;

    while (true) {
        time_t currentTime = time(0);
        int elapsed = difftime(currentTime, startTime);
        int remaining = totalTime - elapsed;

        if (remaining <= 0) {
            cout << "\n=== ВРЕМЯ ВЫШЛО! ===" << endl;
            break;
        }

        game.displayWithTime(remaining);

        int row1, col1, row2, col2;
        cout << "Введите ход (строка1 столбец1 строка2 столбец2): ";
        cin >> row1 >> col1 >> row2 >> col2;

        if (cin.fail() 
            row1 < 0 ||  row1 >= gridSize ||  col1 < 0 || col1 >= gridSize 
            row2 < 0 ||  row2 >= gridSize ||  col2 < 0 || col2 >= gridSize) {
            cout << "Неверные координаты! Используйте числа от 0 до " << gridSize - 1 << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        game.swapTiles(row1, col1, row2, col2);
    }

    cout << "Финальный счет: " << game.getScore() << endl;
}