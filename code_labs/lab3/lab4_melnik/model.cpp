#include <iostream>
#include <limits>
#include "model.h"

using namespace std;

Model::Model(int minRange, int maxRange)
    : attempts(0) {
    cout << "Подумайте о числе между " << minRange << " и " << maxRange << "." << endl;
    cout << "Нажмите Enter, когда будете готовы." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
    targetNumber = findOptimalGuess(minRange, maxRange);
}

int Model::getTargetNumber() const {
    return targetNumber;
}

int Model::getAttempts() const {
    return attempts;
}

bool Model::guessNumber(int guess) {
    attempts++;
    return guess == targetNumber;
}

int Model::findOptimalGuess(int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        cout << "Компьютер предполагает: " << mid << endl;
        cout << "Это правильно? (y/n): ";

        char response = NULL;
        cin >> response;

        if (response == 'y') {
            attempts++;
            return mid;
        }
        else if (response == 'n') {
            cout << "Число больше или меньше, чем " << mid << "? (h/l): ";
            cin >> response;
            attempts++;

            if (response == 'h') {
                low = mid + 1;
            }
            else if (response == 'l') {
                high = mid - 1;
            }
            else {
                cout << "Неверный ответ. Пожалуйста, введите «h» или «l»." << endl;
            }
        }
        else {
            cout << "Неверный ответ. Пожалуйста, введите «y» или «n»." << endl;
        }
    }

    return -1;
}

