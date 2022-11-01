#include <stdio.h>
#include "../utility/utils/utils.h"

Word NORTH = {"NORTH", 5};
Word SOUTH = {"SOUTH", 5};
Word WEST = {"WEST", 4};
Word EAST = {"EAST", 4};

int main() {
    Game game;
    startMenu();
    int input;

    ListWord L;
    createListWord(&L);

    do {
        /* Baca Command START/ EXIT */
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
            while(!game.endGame) {
                sprintBlue("\nEnter Command: \n");
                printf("> ");
                L = readLine();
                input = MenuInput(L.TabWords[0]);

                switch (input) {
                    case 0: /* EXIT */
                        if (L.Length != 1) {
                            sprintRed("Command EXIT tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            game.endGame = true;
                        }
                        break;
                    case 1: /* BUY */
                        if (L.Length != 1) {
                            sprintRed("Command BUY tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            /* code */
                        }
                        break;
                    case 2: /* FRY */
                        if (L.Length != 1) {
                            sprintRed("Command FRY tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            /* code */
                        }
                        break;
                    case 3: /* CHOP */
                        if (L.Length != 1) {
                            sprintRed("Command CHOP tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            /* code */
                        }
                        break;
                    case 4: /* BOIL */
                        if (L.Length != 1) {
                            sprintRed("Command BOIL tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            /* code */
                        }
                        break;
                    case 5: /* MIX */
                        if (L.Length != 1) {
                            sprintRed("Command MIX tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            /* code */
                        }
                        break;
                    case 6: /* HELP */
                        if (L.Length != 1) {
                            sprintRed("Command HELP tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            help();
                        }
                        break;
                    case 7: /* INVENTORY */
                        if (L.Length != 1) {
                            sprintRed("Command INVENTORY tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            /* code */
                        }
                        break;
                    case 8: /* DELIVERY */
                        if (L.Length != 1) {
                            sprintRed("Command DELIVERY tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            /* code */
                        }
                        break;
                    case 9: /* MOVE */
                        if (L.Length != 2) {
                            sprintRed("Command MOVE memiliki 1 argumen, arah. Coba Lagi!\n");
                        } else {
                            boolean stuck, flag = true;
                            if (isWordEq(NORTH, L.TabWords[1])) {
                                MNorth(&game.map, &stuck);
                            } else if (isWordEq(SOUTH, L.TabWords[1])) {
                                MSouth(&game.map, &stuck);
                            } else if (isWordEq(WEST, L.TabWords[1])) {
                                MWest(&game.map, &stuck);
                            } else if (isWordEq(EAST, L.TabWords[1])) {
                                MEast(&game.map, &stuck);
                            } else {
                                sprintRed("Argumen tidak tersedia. Pilih NORTH/ SOUTH/ WEST/ EAST !\n");
                                break;
                            }
                            if (stuck) {
                                sprintRed("Menabrak, Silahkan liat peta!\n");
                            } else {
                                DisplayMap(game.map);
                            }
                            
                        }
                        break;
                    case 10: /* CATALOG */
                        if (L.Length != 1) {
                            sprintRed("Command CATALOG tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            printCatalog(game.listMakanan);
                        }
                        break;
                    case 11: /* COOKBOOK */
                        if (L.Length != 1) {
                            sprintRed("Command COOKBOK tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            /* code */
                        }
                        break;
                    case 12: /* WAIT X Y */
                        if (L.Length != 3) {
                            sprintRed("Command WAIT memiliki 2 argumen. Coba Lagi!\n");
                        } else {
                            /* code */
                        }
                        break;
                    default:
                        sprintRed("Command Invalid. Ketik HELP untuk melihat list Command\n");
                        break;
                }
            }
            if (isEndGame) {
                exitGame();
            }
            break;
        case 2: /* EXIT */
            exitGame();
            break;
        default:
            break;
    }

    return 0;
}