#pragma once

class NumberGame {
private:
    int targetNumber;
    int attempts;
    int maxAttempts;

public:
    NumberGame(int minRange, int maxRange, int maxAttempts);

    int getTargetNumber() const;
    int getAttempts() const;
    bool isGameOver() const;
    bool guessNumber(int guess);
};

