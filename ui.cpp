#include "ui.h"
#include <iostream>

void showRules() {
    std::cout << "\n=== ПРАВИЛА ИГРЫ ===" << std::endl;
    std::cout << "1. Соединяйте 3 и более одинаковых элемента в ряд" << std::endl;
    std::cout << "2. Можно менять местами только соседние элементы" << std::endl;
    std::cout << "3. За каждую совпавшую плитку получаете 10 очков" << std::endl;
    std::cout << "4. Режимы игры:" << std::endl;
    std::cout << "   - На ходы: 20 ходов" << std::endl;
    std::cout << "   - На время: 60 секунд" << std::endl;
    std::cout << "5. Управление: вводите координаты плиток для обмена" << std::endl;
    std::cout << "====================\n" << std::endl;
}

void showMainMenu() {
    std::cout << "=== ТРИ В РЯД ===" << std::endl;
    std::cout << "1. Начать игру" << std::endl;
    std::cout << "2. Правила" << std::endl;
    std::cout << "3. Выход" << std::endl;
    std::cout << "Выберите опцию: ";
}

void showModeMenu() {
    std::cout << "\n=== ВЫБОР РЕЖИМА ===" << std::endl;
    std::cout << "1. На ходы (20 ходов)" << std::endl;
    std::cout << "2. На время (60 секунд)" << std::endl;
    std::cout << "3. Назад" << std::endl;
    std::cout << "Выберите режим: ";
}