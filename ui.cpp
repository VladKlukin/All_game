#include "ui.h"
#include <iostream>
using namespace std;

void showRules() {
    cout << "\n=== ПРАВИЛА ИГРЫ ===" << endl;
    cout << "1. Соединяйте 3 и более одинаковых элемента в ряд" << endl;
    cout << "2. Можно менять местами только соседние элементы" << endl;
    cout << "3. За каждую совпавшую плитку получаете 10 очков" << endl;
    cout << "4. Режимы игры:" << endl;
    cout << "   - На ходы: 20 ходов" << endl;
    cout << "   - На время: 60 секунд" << endl;
    cout << "5. Управление: вводите координаты плиток для обмена" << endl;
    cout << "====================\n" << endl;
}
void showMainMenu() {
    cout << "=== ТРИ В РЯД ===" << endl;
    cout << "1. Начать игру" << endl;
    cout << "2. Правила" << endl;
    cout << "3. Выход" << endl;
    cout << "Выберите опцию: ";
}
void showModeMenu() {
    cout << "\n=== ВЫБОР РЕЖИМА ===" << endl;
    cout << "1. На ходы (20 ходов)" << endl;
    cout << "2. На время (60 секунд)" << endl;
    cout << "3. Назад" << endl;
    cout << "Выберите режим: ";
}