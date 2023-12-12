#pragma once

class Model {
private:
    int targetNumber;
    int attempts;

public:
    Model(int minRange, int maxRange);

    int getTargetNumber() const;
    int getAttempts() const;
    bool guessNumber(int guess);

private:
    int findOptimalGuess(int low, int high);
};

