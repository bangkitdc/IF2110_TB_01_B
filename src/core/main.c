#include <stdio.h>
#include "../utility/utils/utils.h"

Word NORTH = {"NORTH", 5};
Word SOUTH = {"SOUTH", 5};
Word WEST = {"WEST", 4};
Word EAST = {"EAST", 4};

int main() {
    Game game;
    Simulator simulator;
    Stack stack_undo, stack_redo;
    State latest_state;
    ListDinMakanan latest_notification;
    MatrixKulkas kulkas;

    startMenu();
    int input;

    ListWord L;
    createListWord(&L);
    CreateEmpty(&stack_undo);
    CreateEmpty(&stack_redo);
    CreateListMakananDin(&latest_notification, 1000);
    createMatrixKulkas(10, 20, &kulkas);

    do {
        /* Baca Command START/ EXIT */
        printf("\n> ");
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
            startGame(&game, &simulator);
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
                                gerakUser(&simulator, &game.map, &stuck, 'w');
                            } else if (isWordEq(SOUTH, L.TabWords[1])) {
                                gerakUser(&simulator, &game.map, &stuck, 's');
                            } else if (isWordEq(WEST, L.TabWords[1])) {
                                gerakUser(&simulator, &game.map, &stuck, 'a');
                            } else if (isWordEq(EAST, L.TabWords[1])) {
                                gerakUser(&simulator, &game.map, &stuck, 'd');
                            } else {
                                sprintRed("Argumen tidak tersedia. Pilih NORTH/ SOUTH/ WEST/ EAST !\n");
                                break;
                            }
                            if (stuck) {
                                sprintRed("Menabrak, Silahkan liat peta!\n");
                            } else {
                                game.currentTime = NextMenit(game.currentTime);
                                WriteLokasi(simulator.lokasi);
                                TulisTIME3(game.currentTime);
                                printf("\n"); DisplayMap(game.map, simulator.lokasi);
                                simulatorToState(simulator, game.currentTime, latest_notification, kulkas, &latest_state);
                                Push(&stack_undo,latest_state);
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
                            int jam, menit;
                            jam = wordToInt(L.TabWords[1]);
                            menit = wordToInt(L.TabWords[2]);
                            if (jam != -999 && menit != -999) {
                                game.currentTime = NextNMenit(game.currentTime, jam * 60 + menit);
                                WriteLokasi(simulator.lokasi);
                                TulisTIME3(game.currentTime);
                                printf("\n"); DisplayMap(game.map, simulator.lokasi);
                                simulatorToState(simulator, game.currentTime, latest_notification, kulkas, &latest_state);
                                Push(&stack_undo,latest_state);
                            } else {
                                sprintRed("2 Argumen harus integer >= 0. Coba Lagi!\n");
                            }
                        }
                        break;
                    case 13: /* UNDO */
                        if (L.Length != 1) {
                            sprintRed("Command UNDO tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            Undo(&stack_undo, &stack_redo, &latest_state);
                            loadState(&simulator, &latest_state, "ADMIN", &latest_notification, &kulkas, game.currentTime);
                        }
                        break;
                    case 14: /* REDO */
                        if (L.Length != 1) {
                            sprintRed("Command REDO tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            Redo(&stack_undo, &stack_redo, &latest_state);
                            loadState(&simulator, &latest_state, "ADMIN", &latest_notification, &kulkas, game.currentTime);
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