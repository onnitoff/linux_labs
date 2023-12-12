#include "view.h"
#include <iostream>
using namespace std;

void GameView::showWelcomeMessage() const {
    cout << "Добро пожаловать в игру «Попробуй угадать число»!" << std::endl;
}

void GameView::showGuessPrompt() const {
    cout << "Введите свое предположение: ";
}

void GameView::showResult(bool isCorrect, int targetNumber, int attempts) const {
    if (isCorrect) {
        cout << "Поздравляем! Вы угадали число " << targetNumber
            << " за " << attempts << " попыток" << endl;
    }
    else {
        cout << "Игра закончена! Правильный номер был " << targetNumber << "." << endl;
    }
}

void GameView::showTryAgainPrompt() const {
    cout << "Хотите сыграть еще раз? (y/n): ";
}

void GameView::showGoodbyeMessage() const {
    cout << "Спасибо за игру! До свидания." << endl;
}

void GameView::showHigherLowerHint(bool isHigher) const {
    if (isHigher) {
        cout << "Попробуйте большее число." << endl;
    }
    else {
        cout << "Попробуйте меньшее число." << endl;
    }
}

