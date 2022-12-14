#include <stdio.h>
#include "../utility/utils/utils.h"

/* Word for MAIN */
Word NORTH = {"NORTH", 5};
Word SOUTH = {"SOUTH", 5};
Word WEST = {"WEST", 4};
Word EAST = {"EAST", 4};
Word TEMP = {"TEMP", 4};

int main() {
    Game game;
    Simulator simulator;
    Stack stack_undo, stack_redo;
    State latest_state;
    ListDinMakanan latest_notification;
    MatrixKulkas kulkas;
    PrioQueue delivery_list;
    infotype makananDibeli;                 // ini buat nyimpen makanan yang dipilih untuk dibeli

    startMenu();
    int input;

    ListWord L;
    createListWord(&L);
    CreateEmptyStack(&stack_undo);
    CreateEmptyStack(&stack_redo);
    CreateListMakananDin(&latest_notification, 50);
    createMatrixKulkas(10, 20, &kulkas);
    CreateEmptyPrioqueue (&delivery_list, 20);

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
            while(!isEndGame(game)) {
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
                                sprintRed("\nBNMO sedang tidak berada di area telepon(T), silahkan lihat peta!\n");
                            } else {
                                printf("\n======================\n");
                                printf("=        %-4s        =\n", "BUY");
                                printf("======================\n");
                                printf("List Bahan Makanan Yang Bisa Dibeli:\n");
                                ListStatikM makananBisaDibeli;                      //ini buat nyimpen makanan apa aja yang bisa dibeli
                                
                                createLSMakanan(&makananBisaDibeli);
        
                                int no = 1;
                                for (int i=0; i < listLengthStatikM(game.listMakanan); i++) {
                                    if (isMakananBuyable(game.listMakanan.contents[i])) {
                                        insertFood(&makananBisaDibeli, game.listMakanan.contents[i]);
                                        printf("  [%d] %s (", no, NAME(game.listMakanan.contents[i]));
                                        TulisTIME2(DELIVERY(game.listMakanan.contents[i]));
                                        printf(")\n");
                                        no += 1;
                                    }
                                }
                                int PilBuy;
                                PilBuy = select(1, (no - 1));
                                if (PilBuy == 0) {
                                    sprintRed("\nMembatalkan command BUY\n");
                                    break;
                                } else {
                                    PrioQueue tempDelivery;
                                    CreateEmptyPrioqueue(&tempDelivery, 20);
                                    CopyQueue(&delivery_list, &tempDelivery);
                                    
                                    Simulator tempSimulator;
                                    POINT pTemp;
                                    PrioQueue pQueueTemp;
                                    CreatePoint(&pTemp, 0, 0);
                                    CreateEmptyPrioqueue(&pQueueTemp, 50);
                                    createSimulator(&tempSimulator, TEMP, pTemp, pQueueTemp);

                                    copySimulator(&simulator, &tempSimulator);

                                    ListDinMakanan tempNotification;
                                    CreateListMakananDin(&tempNotification, 50);
                                    copyListDinMakanan(latest_notification, &tempNotification);

                                    // Masuk stack undo
                                    simulatorToState(tempSimulator, tempDelivery, game.currentTime, tempNotification, kulkas, &latest_state); 
                                    Push(&stack_undo,latest_state);

                                    // Reset notifikasi
                                    dealocateListMakanan(&latest_notification);
                                    CreateListMakananDin(&latest_notification, 50);

                                    makananDibeli.info = makananBisaDibeli.contents[PilBuy - 1];
                                    makananDibeli.time = makananBisaDibeli.contents[PilBuy - 1].delivery;
                                    TIME lama = PENGOLAHAN(Info(makananDibeli));

                                    game.currentTime = NextNMenit(game.currentTime, TIMEToMenit(lama));
                                    for (int i = 1; i <= TIMEToMenit(lama); i++) {
                                        PasstimeQueue(&Inventory(simulator), 1, &latest_notification);
                                        PassTimeDelivery(&delivery_list, &Inventory(simulator), 1, &latest_notification);
                                    }
                                    
                                    if (TIMEToMenit(makananDibeli.time) != 0) {
                                        Enqueue(&delivery_list, makananDibeli);

                                        printf("\nBerhasil memesan %s. %s akan diantar dalam ", Info(makananDibeli).name, Info(makananDibeli).name);
                                        TulisTIME2(DELIVERY(Info(makananDibeli))); printf(".\n");

                                        // Masukkan ke notif
                                        LOC(Info(makananDibeli)) = 't';
                                        insertLastMakanan(&latest_notification, makananDibeli);
                                        EmptyStack(&stack_redo);
                                    } else {
                                        makananDibeli.time = makananDibeli.info.expiry;
                                        Enqueue(&Inventory(simulator), makananDibeli);
                                        printf("\nBerhasil memesan %s. %s telah masuk inventory\n", Info(makananDibeli).name, Info(makananDibeli).name);
                                        insertLastMakanan(&latest_notification, makananDibeli);
                                        EmptyStack(&stack_redo);
                                    }
                                }
                            }
                        }
                        break;
                    case 2: /* FRY */
                        if (L.Length != 1) {
                            sprintRed("Command FRY tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            boolean CekAdjFry = adjacent(simulator, game.map.Peta, 'F');
                            if (!CekAdjFry) {
                                sprintRed("\nBNMO sedang tidak berada di area fry(F), silahkan lihat peta!\n");
                            } else {
                                ListStatikM makananBisaDiolah;
                                int length, pilFry;
                                displayListMakananAksi(game.listMakanan, &makananBisaDiolah, &length, 'F');
                                pilFry = select(1, length);
                                if (pilFry == 0) {
                                    sprintRed("\nMembatalkan command FRY\n");
                                    break;
                                } else {
                                    mengolahMakanan(makananBisaDiolah.contents[pilFry-1], &simulator, &delivery_list, &latest_notification, kulkas, &stack_undo, &stack_redo, &game, &latest_state);
                                }
                            }
                        }
                        break;
                    case 3: /* CHOP */
                        if (L.Length != 1) {
                            sprintRed("Command CHOP tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            boolean CekAdjChop = adjacent(simulator, game.map.Peta, 'C');
                            if (!CekAdjChop) {
                                sprintRed("\nBNMO sedang tidak berada di area chop(C), silahkan lihat peta!\n");
                            } else {
                                ListStatikM makananBisaDiolah;
                                int length, pilChop;
                                displayListMakananAksi(game.listMakanan, &makananBisaDiolah, &length, 'C');
                                pilChop = select(1, length);
                                if (pilChop == 0) {
                                    sprintRed("\nMembatalkan command CHOP\n");
                                    break;
                                } else {
                                    mengolahMakanan(makananBisaDiolah.contents[pilChop-1], &simulator, &delivery_list, &latest_notification, kulkas, &stack_undo, &stack_redo, &game, &latest_state);
                                }
                            }
                        }
                        break;
                    case 4: /* BOIL */
                        if (L.Length != 1) {
                            sprintRed("Command BOIL tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            boolean CekAdjBoil = adjacent(simulator, game.map.Peta, 'B');
                            if (!CekAdjBoil) {
                                sprintRed("\nBNMO sedang tidak berada di area boil(B), silahkan lihat peta!\n");
                            } else {
                                ListStatikM makananBisaDiolah;
                                int length, pilBoil;
                                displayListMakananAksi(game.listMakanan, &makananBisaDiolah, &length, 'B');
                                pilBoil = select(1, length);
                                if (pilBoil == 0) {
                                    sprintRed("\nMembatalkan command BOIL\n");
                                    break;
                                } else {
                                    mengolahMakanan(makananBisaDiolah.contents[pilBoil-1], &simulator, &delivery_list, &latest_notification, kulkas, &stack_undo, &stack_redo, &game, &latest_state);
                                }
                            }
                        }
                        break;
                    case 5: /* MIX */
                        if (L.Length != 1) {
                            sprintRed("Command MIX tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            boolean CekAdjMix = adjacent(simulator, game.map.Peta, 'M');
                            if (!CekAdjMix) {
                                sprintRed("\nBNMO sedang tidak berada di area mix(M), silahkan lihat peta!\n");
                            } else {
                                ListStatikM makananBisaDiolah;
                                int length, pilMix;
                                displayListMakananAksi(game.listMakanan, &makananBisaDiolah, &length, 'M');
                                pilMix = select(1, length);
                                if (pilMix == 0) {
                                    sprintRed("\nMembatalkan command MIX\n");
                                    break;
                                } else {
                                    mengolahMakanan(makananBisaDiolah.contents[pilMix-1], &simulator, &delivery_list, &latest_notification, kulkas, &stack_undo, &stack_redo, &game, &latest_state);
                                }
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
                            PrioQueue tempDelivery;
                            CreateEmptyPrioqueue(&tempDelivery, 20);
                            CopyQueue(&delivery_list, &tempDelivery);
                            
                            Simulator tempSimulator;
                            POINT pTemp;
                            PrioQueue pQueueTemp;
                            CreatePoint(&pTemp, 0, 0);
                            CreateEmptyPrioqueue(&pQueueTemp, 50);
                            createSimulator(&tempSimulator, TEMP, pTemp, pQueueTemp);

                            copySimulator(&simulator, &tempSimulator);

                            ListDinMakanan tempNotification;
                            CreateListMakananDin(&tempNotification, 50);
                            copyListDinMakanan(latest_notification, &tempNotification);

                            // Masuk stack undo
                            simulatorToState(tempSimulator, tempDelivery, game.currentTime, tempNotification, kulkas, &latest_state);
                            Push(&stack_undo,latest_state);

                            // Reset notifikasi
                            dealocateListMakanan(&latest_notification);
                            CreateListMakananDin(&latest_notification, 50);
                            
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
                                PasstimeQueue(&Inventory(simulator), 1, &latest_notification);
                                PassTimeDelivery(&delivery_list, &Inventory(simulator), 1, &latest_notification);
                                WriteLokasi(simulator.lokasi);
                                TulisTIME3(game.currentTime);
                                printListMakanan(latest_notification);
                                printf("\n"); 
                                DisplayMap(game.map, simulator.lokasi);
                                EmptyStack(&stack_redo);
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
                                PrioQueue tempDelivery;
                                CreateEmptyPrioqueue(&tempDelivery, 20);
                                CopyQueue(&delivery_list, &tempDelivery);
                                
                                Simulator tempSimulator;
                                POINT pTemp;
                                PrioQueue pQueueTemp;
                                CreatePoint(&pTemp, 0, 0);
                                CreateEmptyPrioqueue(&pQueueTemp, 50);
                                createSimulator(&tempSimulator, TEMP, pTemp, pQueueTemp);

                                copySimulator(&simulator, &tempSimulator);

                                ListDinMakanan tempNotification;
                                CreateListMakananDin(&tempNotification, 50);
                                copyListDinMakanan(latest_notification, &tempNotification);

                                // Masuk stack undo
                                simulatorToState(tempSimulator, tempDelivery, game.currentTime, tempNotification, kulkas, &latest_state);
                                Push(&stack_undo,latest_state);

                                // reset notifikasi
                                dealocateListMakanan(&latest_notification);
                                CreateListMakananDin(&latest_notification, 50);
                                game.currentTime = NextNMenit(game.currentTime, jam * 60 + menit);
                                for (int i = 1; i <= jam * 60 + menit; i++) {
                                    PasstimeQueue(&Inventory(simulator), 1, &latest_notification);
                                    PassTimeDelivery(&delivery_list, &Inventory(simulator), 1, &latest_notification);
                                }

                                WriteLokasi(simulator.lokasi);
                                TulisTIME3(game.currentTime);
                                printListMakanan(latest_notification);
                                printf("\n");
                                DisplayMap(game.map, simulator.lokasi);
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
                                ListDinMakanan tempnotif;
                                CreateListMakananDin(&tempnotif, 50);
                                copyListDinMakanan(latest_notification, &tempnotif);

                                simulatorToState(simulator, delivery_list, game.currentTime, latest_notification, kulkas, &latest_state);
                                
                                Undo(&stack_undo, &stack_redo, &latest_state);
                                loadState(&simulator, &delivery_list, latest_state, simulator.username, &latest_notification, &kulkas, &game.currentTime);
                                WriteLokasi(simulator.lokasi);
                                TulisTIME3(game.currentTime);
                                printListMakananUndo(tempnotif);
                                printf("\n");
                                DisplayMap(game.map, simulator.lokasi);
                            } else {
                                sprintRed("Tidak bisa UNDO. (UNDO max: 25 times)\n");
                            }
                        }
                        break;
                    case 14: /* REDO */
                        if (L.Length != 1) {
                            sprintRed("Command REDO tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            if (!IsStackEmpty(stack_redo)) {
                                simulatorToState(simulator, delivery_list, game.currentTime, latest_notification, kulkas, &latest_state);
                                Redo(&stack_undo, &stack_redo, &latest_state);
                                loadState(&simulator, &delivery_list, latest_state, simulator.username, &latest_notification, &kulkas, &game.currentTime);
                                WriteLokasi(simulator.lokasi);
                                TulisTIME3(game.currentTime);
                                printListMakanan(latest_notification);
                                printf("\n");
                                DisplayMap(game.map, simulator.lokasi);
                            } else {
                                sprintRed("Tidak bisa REDO.\n");
                            }
                        }
                        break;
                    case 15: /* MASUKKULKAS X Y*/
                        if (L.Length != 3) {
                            sprintRed("Command MASUKKULKAS memiliki 2 argumen. Coba Lagi!\n");
                        } else {
                            displayMatrixKulkas(kulkas);
                            infotype tempinfotype;
                            boolean idtidakvalid;
                            ListWord tempindexkulkas;
                            int inputtempindexkulkas;
                            createListWord(&tempindexkulkas);
                            int X = wordToInt(L.TabWords[1]);
                            int Y = wordToInt(L.TabWords[2]);
                            
                            if (X <= NBElmtPrioqueue(Inventory(simulator)) && X > 0) {
                                if (!isFullKulkas(kulkas)) {
                                    ambilDariInventory(&simulator, X-1, &tempinfotype);
                                    penomorMakananKulkas(&tempinfotype, Y, kulkas, &idtidakvalid);
                                    if (!idtidakvalid) {
                                        if (Absis(SIZE(Info(tempinfotype))) * Ordinat(SIZE(Info(tempinfotype))) <= countElmtDummy(kulkas)) {
                                            // Minta input index pojok kiri atas dan index pojok kanan bawah
                                            sprintYellow("\nMasukkan index pojok kiri atas, dan index pojok kanan bawah\n");
                                            sprintYellow("Urutannya: kiri atas kanan bawah\n");
                                            printf("> ");
                                            tempindexkulkas = readLine();
                                            inputtempindexkulkas = MenuInput(tempindexkulkas.TabWords[0]);
                                            if (tempindexkulkas.Length != 4) {
                                                sprintRed("Butuh 2 titik x1(a,b) x2(c,d)\n");
                                                
                                                // Kembalikan ID awal
                                                hapusIdKulkas(&tempinfotype);
                                                Enqueue(&Inventory(simulator), tempinfotype);
                                            } else {
                                                int kiri = wordToInt(tempindexkulkas.TabWords[0]);
                                                int atas = wordToInt(tempindexkulkas.TabWords[1]);
                                                int kanan = wordToInt(tempindexkulkas.TabWords[2]);
                                                int bawah = wordToInt(tempindexkulkas.TabWords[3]);
                                                if ((bawah - atas + 1) * (kanan - kiri + 1) != Absis(SIZE(Info(tempinfotype))) * Ordinat(SIZE(Info(tempinfotype)))) {
                                                    sprintRed("Index tidak valid.. :(\n");
                                                    // Kembalikan ID awal
                                                    hapusIdKulkas(&tempinfotype);
                                                    Enqueue(&Inventory(simulator), tempinfotype);
                                                } else {
                                                    int i, j;
                                                    boolean idxkulkasvalid;

                                                    idxkulkasvalid = true;

                                                    // Mengecek apakah index kulkas valid, yakni saat tidak ada makanan lain
                                                    // di posisi tersebut
                                                    for (i = atas; i <= bawah; i++) {
                                                        for (j = kiri; j <= kanan; j++) {
                                                            if (ID(Info(ELMTK(kulkas,i,j))) != 0) {
                                                                idxkulkasvalid = false;
                                                            }
                                                        }
                                                    }

                                                    if (idxkulkasvalid) {
                                                        PrioQueue tempDelivery;
                                                        CreateEmptyPrioqueue(&tempDelivery, 20);
                                                        CopyQueue(&delivery_list, &tempDelivery);
                                                        
                                                        Simulator tempSimulator;
                                                        POINT pTemp;
                                                        PrioQueue pQueueTemp;
                                                        CreatePoint(&pTemp, 0, 0);
                                                        CreateEmptyPrioqueue(&pQueueTemp, 50);
                                                        createSimulator(&tempSimulator, TEMP, pTemp, pQueueTemp);

                                                        copySimulator(&simulator, &tempSimulator);

                                                        ListDinMakanan tempNotification;
                                                        CreateListMakananDin(&tempNotification, 50);
                                                        copyListDinMakanan(latest_notification, &tempNotification);

                                                        // Masuk stack undo
                                                        simulatorToState(tempSimulator, tempDelivery, game.currentTime, tempNotification, kulkas, &latest_state);
                                                        Push(&stack_undo,latest_state);

                                                        // Reset notifikasi
                                                        dealocateListMakanan(&latest_notification);
                                                        CreateListMakananDin(&latest_notification, 50);

                                                        for (i = atas; i <= bawah; i++) {
                                                            for (j = kiri; j <= kanan; j++) {
                                                                pindahKeKulkas(tempinfotype, &kulkas, &latest_notification, i, j);
                                                            }
                                                        }
                                                        EmptyStack(&stack_redo);
                                                    } else { // idxkulkasvalid == false
                                                        sprintRed("Ada makanan lain di posisi tersebut..\n");
                                                        // Kembalikan ID awal
                                                        hapusIdKulkas(&tempinfotype);
                                                        Enqueue(&Inventory(simulator), tempinfotype);
                                                    }
                                                }
                                            }
                                        } else { // Absis(SIZE(Info(tempinfotype))) * Ordinat(SIZE(Info(tempinfotype))) > countElmtDummy(kulkas)
                                            sprintRed("Kulkas tidak bisa menampung makanan kamu :(\n");
                                            // Kembalikan ID awal
                                            hapusIdKulkas(&tempinfotype);
                                            Enqueue(&Inventory(simulator), tempinfotype);
                                        }
                                    } else {
                                        Enqueue(&Inventory(simulator), tempinfotype);
                                    }
                                } else { // isFullKulkas(kulkas)
                                    sprintRed("Kulkas sudah penuh.. :(\n");
                                }
                            } else {
                                sprintRed("Tidak ada makanan pada urutan tersebut di Inventory.. :(\n");   
                            }
                        }
                        break;
                    case 16: /* KELUARKULKAS X*/
                        if (L.Length != 2) {
                            sprintRed("Command KELUARKULKAS memiliki 1 argumen. Coba Lagi!\n");
                        } else {
                            int tempidmakanan, i, j;
                            boolean ada;
                            tempidmakanan = wordToInt(L.TabWords[1]);

                            // Cek terlebih dahulu apakah ada makanan di kulkas dengan ID tersebut
                            ada = false;
                            for (i = 0; i <= 9; i++) {
                                for (j = 0; j <= 19; j++) {
                                    if (ID(Info(ELMTK(kulkas, i, j))) == tempidmakanan) {
                                        ada = true;
                                    }
                                }
                            }

                            if (!ada) {
                                sprintRed("Tidak ada makanan dengan ID tersebut di kulkas\n");
                            } else {
                                PrioQueue tempDelivery;
                                CreateEmptyPrioqueue(&tempDelivery, 20);
                                CopyQueue(&delivery_list, &tempDelivery);
                                
                                Simulator tempSimulator;
                                POINT pTemp;
                                PrioQueue pQueueTemp;
                                CreatePoint(&pTemp, 0, 0);
                                CreateEmptyPrioqueue(&pQueueTemp, 50);
                                createSimulator(&tempSimulator, TEMP, pTemp, pQueueTemp);

                                copySimulator(&simulator, &tempSimulator);

                                ListDinMakanan tempNotification;
                                CreateListMakananDin(&tempNotification, 50);
                                copyListDinMakanan(latest_notification, &tempNotification);

                                // Masuk stack undo
                                simulatorToState(tempSimulator, tempDelivery, game.currentTime, tempNotification, kulkas, &latest_state);
                                Push(&stack_undo,latest_state);

                                // Reset notifikasi
                                dealocateListMakanan(&latest_notification);
                                CreateListMakananDin(&latest_notification, 50);

                                // Ambil dari kulkas
                                ambilDariKulkas(&simulator, tempidmakanan, &kulkas, &latest_notification);
                                EmptyStack(&stack_redo);
                                
                                displayMatrixKulkas(kulkas);
                            }
                        }
                        break;
                    case 17: /*KULKAS*/
                        if (L.Length != 1) {
                            sprintRed("Command KULKAS tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            displayMatrixKulkas(kulkas);
                        }
                        break;
                    case 18: /*REKOMENDASI*/
                        if (L.Length != 1) {
                            sprintRed("Command REKOMENDASI tidak memiliki argumen. Coba Lagi!\n");
                        } else {
                            if (IsEmptyPrioqueue(simulator.inventory)) {
                                sprintRed("\nInventory kosong, tidak ada rekomendasi makanan.\n");
                            } else {
                                rekomendasiMakanan(game.listMakanan, simulator.inventory, game.listResep);
                            }
                        }
                        break;
                    default:
                        sprintRed("Command Invalid. Ketik HELP untuk melihat list Command\n");
                        break;   
                    }
                }
                if (isEndGame(game)) {
                    printf("\nSemangat yak ><, %s", wordToString(simulator.username));
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