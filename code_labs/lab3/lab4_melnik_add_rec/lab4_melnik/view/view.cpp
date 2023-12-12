#include <iostream>
#include "view.h"

using namespace std;

void View::congratulate(int targetNumber, int attempts) const {
    cout << "Поздравляем! Компьютер угадал ваш номер " << targetNumber
        << " за " << attempts << " попытки." << endl;
}

