#include <cstdlib>
#include <ctime>
#include "model.h"

NumberGame::NumberGame(int minRange, int maxRange, int maxAttempts)
    : maxAttempts(maxAttempts), attempts(0) {
    srand(static_cast<unsigned>(time(nullptr)));
    targetNumber = rand() % (maxRange - minRange + 1) + minRange;
}

int NumberGame::getTargetNumber() const {
    return targetNumber;
}

int NumberGame::getAttempts() const {
    return attempts;
}

bool NumberGame::isGameOver() const {
    return attempts >= maxAttempts;
}

bool NumberGame::guessNumber(int guess) {
    attempts++;
    return guess == targetNumber;
}

