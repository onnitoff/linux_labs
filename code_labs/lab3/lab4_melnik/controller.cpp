#include <iostream>
#include "controller.h"

using namespace std;

void Controller::runGame() {
    setlocale(LC_ALL, "Russian");
    const int minRange = 1;
    const int maxRange = 100;

    Model game(minRange, maxRange);
    View view;

    view.congratulate(game.getTargetNumber(), game.getAttempts());
}

