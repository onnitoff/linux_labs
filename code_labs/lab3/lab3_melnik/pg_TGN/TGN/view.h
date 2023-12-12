#pragma once

class GameView {
public:
    void showWelcomeMessage() const;
    void showGuessPrompt() const;
    void showResult(bool isCorrect, int targetNumber, int attempts) const;
    void showTryAgainPrompt() const;
    void showGoodbyeMessage() const;
    void showHigherLowerHint(bool isHigher) const;
};

