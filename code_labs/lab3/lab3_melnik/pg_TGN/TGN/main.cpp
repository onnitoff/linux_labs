#include "controller.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    const int minRange = 1;
    const int maxRange = 100;
    const int maxAttempts = 10;

    GameController gameController(minRange, maxRange, maxAttempts);
    gameController.startGame();

    return 0;
}

