#pragma once
#include "model.h"
#include "view.h"

class GameController {
private:
    NumberGame model;
    GameView view;

public:
    GameController(int minRange, int maxRange, int maxAttempts);

    void startGame();

private:
    void playRound();
    bool playAgain();
};

