#include <stdio.h>
#include "../utility/utils/utils.h"

int main() {
    Game game;
    startMenu();
    int input;

    do {
        /* Baca Command START/ EXIT */
        ListWord L;
        createListWord(&L);
        printf("> ");
        L = readLine();

        if (L.Length == 1) {
            input = startInput(L.TabWords[0]);
        } else {
            input = -1;
        }
        if (input == -1) {
            sprintRed("Input tidak valid. Ulangi input!\n");
        }
    } while (input == -1);

    switch (input) {
        case 1: /* START */
            startGame(&game);
            // while(!game.endGame) {

            // }
            break;
        case 2: /* EXIT */
            exitGame();
            break;
        default:
            break;
    }

    return 0;
}