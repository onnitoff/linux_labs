#include <iostream>
#include <limits>
#include "controller.h"
using namespace std;
GameController::GameController(int minRange, int maxRange, int maxAttempts)
    : model(minRange, maxRange, maxAttempts) {}

void GameController::startGame() {
    view.showWelcomeMessage();

    do {
        playRound();
    } while (playAgain());

    view.showGoodbyeMessage();
}

void GameController::playRound() {
    while (!model.isGameOver()) {
        view.showGuessPrompt();
        int guess;
        cin >> guess;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный Ввод. Пожалуйста введите правильное число." << endl;
            continue;
        }

        if (model.guessNumber(guess)) {
            view.showResult(true, model.getTargetNumber(), model.getAttempts());
            return;
        }
        else {
            view.showHigherLowerHint(guess < model.getTargetNumber());
        }
    }

    view.showResult(false, model.getTargetNumber(), model.getAttempts());
}

bool GameController::playAgain() {
    char choice;
    do {
        view.showTryAgainPrompt();
        cin >> choice;
    } while (choice != 'y' && choice != 'n');

    return choice == 'y';
}

