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
    PrioQueue delivery_list;

    startMenu();
    int input;

    ListWord L;
    createListWord(&L);
    CreateEmptyStack(&stack_undo);
    CreateEmptyStack(&stack_redo);
    CreateListMakananDin(&latest_notification, 1000);
    createMatrixKulkas(10, 20, &kulkas);
    CreateEmptyPrioqueue (&delivery_list, 100);

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
                            boolean CekAdjBuy = adjacent(simulator, game.map.Peta, 'T');
                            if (!CekAdjBuy) {
                                sprintRed("\nBNMO sedang tidak berada di area telepon!\n");
                            } else {
                                printf("List Bahan Makanan:\n");
                                ListStatikM makananBisaDibeli; //ini buat nyimpen makanan apa aja yang bisa dibeli
                                infotype makananDibeli;  // ini buat nyimpen makanan yang dipilih untuk dibeli
                                createLSMakanan(&makananBisaDibeli);
                                int no = 1;
                                for (int i=0; i < listLengthStatikM(game.listMakanan); i++) {
                                    if (isMakananBuyable(game.listMakanan.contents[i])) {
                                        printf("  [%d] %s (", no, NAME(game.listMakanan.contents[i]));
                                        TulisTIME2(DELIVERY(game.listMakanan.contents[i]));
                                        printf(")\n");
                                        no += 1;
                                    }
                                }
                                int PilBuy;
                                PilBuy = select(1, no);
                                if (PilBuy == 0) {
                                    sprintRed("\nMembatalkan command BUY\n");
                                    break;
                                } else {

                                }
                            }
                        }
                        break;
                    case 2: /* FRY */
                        if (L.Length != 1) {
                            sprintRed("Command FRY tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            ListStatikM makananBisaDiolah;
                            int length, pilih;
                            char c;
                            displayListMakananAksi(game.listMakanan, &makananBisaDiolah, &length, 'F');
                            sprintBlue("\nEnter Command: \n");
                            printf("> ");
                            scanf("%d", &pilih);
                            scanf("%c", &c); // hanya untuk tidak terjadi command error karena karakter enter
                            if(pilih>=1 && pilih <= length){
                                mengolahMakanan(makananBisaDiolah.contents[pilih-1], &(simulator.inventory), game.listResep, game.listMakanan);
                            }
                        }
                        break;
                    case 3: /* CHOP */
                        if (L.Length != 1) {
                            sprintRed("Command CHOP tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            ListStatikM makananBisaDiolah;
                            int length, pilih;
                            char c;
                            displayListMakananAksi(game.listMakanan, &makananBisaDiolah, &length, 'C');
                            sprintBlue("\nEnter Command: \n");
                            printf("> ");
                            scanf("%d", &pilih);
                            scanf("%c", &c); // hanya untuk tidak terjadi command error karena karakter enter
                            if(pilih>=1 && pilih <= length){
                                mengolahMakanan(makananBisaDiolah.contents[pilih-1], &(simulator.inventory), game.listResep, game.listMakanan);
                            }
                        }
                        break;
                    case 4: /* BOIL */
                        if (L.Length != 1) {
                            sprintRed("Command BOIL tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            ListStatikM makananBisaDiolah;
                            int length, pilih;
                            char c;
                            displayListMakananAksi(game.listMakanan, &makananBisaDiolah, &length, 'B');
                            sprintBlue("\nEnter Command: \n");
                            printf("> ");
                            scanf("%d", &pilih);
                            scanf("%c", &c); // hanya untuk tidak terjadi command error karena karakter enter
                            if(pilih>=1 && pilih <= length){
                                mengolahMakanan(makananBisaDiolah.contents[pilih-1], &(simulator.inventory), game.listResep, game.listMakanan);
                            }
                        }
                        break;
                    case 5: /* MIX */
                        if (L.Length != 1) {
                            sprintRed("Command MIX tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            ListStatikM makananBisaDiolah;
                            int length, pilih;
                            char c;
                            displayListMakananAksi(game.listMakanan, &makananBisaDiolah, &length, 'M');
                            sprintBlue("\nEnter Command: \n");
                            printf("> ");
                            scanf("%d", &pilih);
                            scanf("%c", &c); // hanya untuk tidak terjadi command error karena karakter enter
                            if(pilih>=1 && pilih <= length){
                                mengolahMakanan(makananBisaDiolah.contents[pilih-1], &(simulator.inventory), game.listResep, game.listMakanan);
                            }
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
                            PrintPrioQueue(simulator.inventory);
                        }
                        break;
                    case 8: /* DELIVERY */
                        if (L.Length != 1) {
                            sprintRed("Command DELIVERY tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            PrintPrioQueueDelivery(delivery_list);
                        }
                        break;
                    case 9: /* MOVE */
                        if (L.Length != 2) {
                            sprintRed("Command MOVE memiliki 1 argumen, arah. Coba Lagi!\n");
                        } else {
                            boolean stuck, flag = true;
                            if (isWordEq(NORTH, L.TabWords[1])) {
                                simulatorToState(simulator, game.currentTime, latest_notification, kulkas, &latest_state);
                                Push(&stack_undo, latest_state);
                                gerakUser(&simulator, &game.map, &stuck, 'w');
                                EmptyStack(&stack_redo);
                            } else if (isWordEq(SOUTH, L.TabWords[1])) {
                                simulatorToState(simulator, game.currentTime, latest_notification, kulkas, &latest_state);
                                Push(&stack_undo,latest_state);
                                gerakUser(&simulator, &game.map, &stuck, 's');
                                EmptyStack(&stack_redo);
                            } else if (isWordEq(WEST, L.TabWords[1])) {
                                simulatorToState(simulator, game.currentTime, latest_notification, kulkas, &latest_state);
                                Push(&stack_undo,latest_state);
                                gerakUser(&simulator, &game.map, &stuck, 'a');
                                EmptyStack(&stack_redo);
                            } else if (isWordEq(EAST, L.TabWords[1])) {
                                simulatorToState(simulator, game.currentTime, latest_notification, kulkas, &latest_state);
                                Push(&stack_undo,latest_state);
                                gerakUser(&simulator, &game.map, &stuck, 'd');
                                EmptyStack(&stack_redo);
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
                            printCookBook(game.listResep, game.listMakanan);
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
                                simulatorToState(simulator, game.currentTime, latest_notification, kulkas, &latest_state);
                                Push(&stack_undo,latest_state);
                                game.currentTime = NextNMenit(game.currentTime, jam * 60 + menit);
                                WriteLokasi(simulator.lokasi);
                                TulisTIME3(game.currentTime);
                                printf("\n"); DisplayMap(game.map, simulator.lokasi);
                                EmptyStack(&stack_redo);
                            } else {
                                sprintRed("2 Argumen harus integer >= 0. Coba Lagi!\n");
                            }
                        }
                        break;
                    case 13: /* UNDO */
                        if (L.Length != 1) {
                            sprintRed("Command UNDO tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            if (!IsStackEmpty(stack_undo)) {
                                simulatorToState(simulator, game.currentTime, latest_notification, kulkas, &latest_state);
                                Undo(&stack_undo, &stack_redo, &latest_state);
                                loadState(&simulator, &latest_state, "ADMIN", &latest_notification, &kulkas, &game.currentTime);
                                WriteLokasi(simulator.lokasi);
                                TulisTIME3(game.currentTime);
                                printf("\n"); DisplayMap(game.map, simulator.lokasi);
                            } else {
                                sprintRed("Tidak bisa UNDO.\n");
                            }
                        }
                        break;
                    case 14: /* REDO */
                        if (L.Length != 1) {
                            sprintRed("Command REDO tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            if (!IsStackEmpty(stack_redo)) {
                                simulatorToState(simulator, game.currentTime, latest_notification, kulkas, &latest_state);
                                Redo(&stack_undo, &stack_redo, &latest_state);
                                loadState(&simulator, &latest_state, "ADMIN", &latest_notification, &kulkas, &game.currentTime);
                                WriteLokasi(simulator.lokasi);
                                TulisTIME3(game.currentTime);
                                printf("\n"); DisplayMap(game.map, simulator.lokasi);
                            } else {
                                sprintRed("Tidak bisa REDO.\n");
                            }
                        }
                        break;
                    case 15: /* MASUKKULKAS X Y Z*/
                        if (L.Length != 4) {
                            sprintRed("Command MASUKKULKAS memiliki 3 argumen. Coba Lagi!\n");
                        } else {
                            // infotype tempinfotype;
                            // boolean idtidakvalid;
                            // ListWord tempindexkulkas;
                            // createListWord(&tempindexkulkas);
                            // int X = wordToInt(L.TabWords[1]);
                            // int Y = wordToInt(L.TabWords[2]);
                            // int Z = wordToInt(L.TabWords[3]); // Z == 1, secara landscape, selain itu secara portrait

                            // if (!isFullKulkas(kulkas)) {
                            //     ambilDariInventory(&simulator, X, &tempinfotype);
                            //     penomorMakananKulkas(&tempinfotype, Y, kulkas, &idtidakvalid)
                            //     if (!idtidakvalid) {
                            //         if (Absis(SIZE(Info(tempinfotype))) * Ordinat(SIZE(Info(tempinfotype))) <= countElmtDummy(kulkas)) {
                            //             if (Z == 1) {
                            //                 // minta input index
                            //             } else {
                            //                 // minta input index
                            //             }
                            //         } else {
                            //             sprintRed("Kulkas tidak bisa menampung makanan kamu :(\n");
                            //         }
                            //     }
                            // } else {
                            //     sprintRed("Kulkas sudah penuh.. :(\n");
                            // }
                        }
                        break;
                    case 16: /* KELUARKULKAS X Y*/
                        if (L.Length != 3) {
                            sprintRed("Command KELUARKULKAS memiliki 2 argumen. Coba Lagi!\n");
                        } else {
                            
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