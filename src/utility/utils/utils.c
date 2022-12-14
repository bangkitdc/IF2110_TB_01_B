#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "../../include/boolean.h"

/* SPLASH SCREEN */
const char *bnmo[] = {
    "        .................        ",
    "      .IIIIIIIIIIIIIIIIIII.      ",
    "      :IIIVVVVVVVVVVVVVIII:      ",
    "      :III             III:      ",
    " **   :III  vs     sv  III:   **       ___           ___           ___           ___      ",
    " *N*  :III             III:  *N*      /\\  \\         /\\__\\         /\\__\\         /\\  \\     ",
    "  FM. :III     *V*     III: .MI      /::\\  \\       /::|  |       /::|  |       /::\\  \\    ",
    "  .NV :III             III: VN.     /:/\\:\\  \\     /:|:|  |      /:|:|  |      /:/\\:\\  \\   ",
    "   *N::IIIIFFFFFFFFFIIIIII::N*     /::\\~\\:\\__\\   /:/|:|  |__   /:/|:|__|__   /:/  \\:\\  \\  ",
    "    IM:IIIMMMMMMMIIIM$IIII:IM     /:/\\:\\ \\:|__| /:/ |:| /\\__\\ /:/ |::::\\__\\ /:/__/ \\:\\__\\ ",
    "    :NFIIIIIIVFIIIIIIIIIIIFN:     \\:\\~\\:\\/:/  / \\/__|:|/:/  / \\/__/~~/:/  / \\:\\  \\ /:/  / ",
    "     V$IIIIVV*VVIIIIIIIIII$V       \\:\\ \\::/  /      |:/:/  /        /:/  /   \\:\\  /:/  /  ",
    "     .NIIIIFV*VVIIIIIIIFIIN.        \\:\\/:/  /       |::/  /        /:/  /     \\:\\/:/  /   ",
    "      *IIIIIIFIIIIIIMMIIII*          \\::/__/        /:/  /        /:/  /       \\::/  /    ",
    "      :IIMNNMINNNIIMMMMIII:           ~~            \\/__/         \\/__/         \\/__/     ",
    "      .IIINMIIIIIIIIMMNIII.      ",
    "        .:NN:       :NN:.        ",
    "          **         **          ",
};

/* Word Utility */
Word START_COMMAND = {"START", 5};
Word EXIT_COMMAND = {"EXIT", 4};
Word BUY_COMMAND = {"BUY", 3};
Word FRY_COMMAND = {"FRY", 3};
Word CHOP_COMMAND = {"CHOP", 4};
Word BOIL_COMMAND = {"BOIL", 4};
Word MIX_COMMAND = {"MIX", 3};
Word HELP_COMMAND = {"HELP", 4};
Word INVENTORY_COMMAND = {"INVENTORY", 9};
Word DELIVERY_COMMAND = {"DELIVERY", 8};
Word MOVE_COMMAND = {"MOVE", 4};
Word CATALOG_COMMAND = {"CATALOG", 7};
Word COOKBOOK_COMMAND = {"COOKBOOK", 8};
Word WAIT_COMMAND = {"WAIT", 4};
Word UNDO_COMMAND = {"UNDO", 4};
Word REDO_COMMAND = {"REDO", 4};
Word MASUKKULKAS_COMMAND = {"MASUKKULKAS", 11};
Word KELUARKULKAS_COMMAND = {"KELUARKULKAS", 12};
Word KULKAS_COMMAND = {"KULKAS", 6};
Word REKOMENDASI_COMMAND = {"REKOMENDASI", 11};

Word BUY_FILE = {"Buy", 3};
Word FRY_FILE = {"Fry", 3};
Word CHOP_FILE = {"Chop", 4};
Word BOIL_FILE = {"Boil", 4};
Word MIX_FILE = {"Mix", 3};

void startMenu() {
    int i;
    for (i = 0; i < 18; i++) {
        printf("%s%d%c%d%c%d%c%s%s\n",
               "\x1B[38;2;",
               0, ';', (204 - i * 4), ';', (i * 9 + 90), 'm',
               bnmo[i],
               "\x1B[0m");
    }
    printf("\n");
    sprintCyan("============================\n");
    sprintCyan("=       List Command       =\n");
    sprintCyan("============================\n");
    sprintGreen("[1] START \n");
    sprintRed("[2] EXIT \n");
}

int startInput(Word w)
{
    if (isWordEq(w, START_COMMAND))
    {
        return 1;
    }
    else if (isWordEq(w, EXIT_COMMAND))
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

int MenuInput(Word w)
{
    ListWord LCommand = {
        {EXIT_COMMAND,
         BUY_COMMAND,
         FRY_COMMAND,
         CHOP_COMMAND,
         BOIL_COMMAND,
         MIX_COMMAND,
         HELP_COMMAND,
         INVENTORY_COMMAND,
         DELIVERY_COMMAND,
         MOVE_COMMAND,
         CATALOG_COMMAND,
         COOKBOOK_COMMAND,
         WAIT_COMMAND,
         UNDO_COMMAND,
         REDO_COMMAND,
         MASUKKULKAS_COMMAND,
         KELUARKULKAS_COMMAND,
         KULKAS_COMMAND,
         REKOMENDASI_COMMAND},
        19};

    for (int i = 0; i < 19; i++)
    {
        if (isWordEq(w, LCommand.TabWords[i]))
        {
            return i;
        }
    }
    return -1;
}

void inputConfigFile(Game *g, Simulator *sim, char *PATH, int type)
{
    STARTWORDFILE(PATH);

    if (!EndWord)
    {
        ListWord LFile;
        createListWord(&LFile);

        LFile = readLineFile();

        switch (type)
        {
        case 1: /* Config Makanan */;
            int n;
            n = wordToInt(LFile.TabWords[0]); /* Jumlah Makanan */

            ADVNewline();
            int i, j, k;
            for (i = 0; i < n; i++)
            {
                Makanan M;
                int id, day1, hour1, min1, day2, hour2, min2, day3, hour3, min3;
                char *name;
                TIME exp, delivery, pengolahan;
                char loc;
                POINT size;
                for (j = 0; j < 6; j++)
                {
                    LFile = readLineFile();
                    switch (j)
                    {
                    case 0: /* ID */
                        id = wordToInt(LFile.TabWords[0]);
                        break; /* Nama Makanan */
                    case 1:
                        name = ListWordToString(LFile);
                        break;
                    case 2: /* Waktu Expired */
                        day1 = wordToInt(LFile.TabWords[0]);
                        hour1 = wordToInt(LFile.TabWords[1]);
                        min1 = wordToInt(LFile.TabWords[2]);
                        CreateTime(&exp, day1, hour1, min1);
                        break;
                    case 3: /* Waktu Delivery */
                        day2 = wordToInt(LFile.TabWords[0]);
                        hour2 = wordToInt(LFile.TabWords[1]);
                        min2 = wordToInt(LFile.TabWords[2]);
                        CreateTime(&delivery, day2, hour2, min2);
                        break;
                    case 4: /* Lokasi Aksi */
                        if (isWordEq(BUY_FILE, LFile.TabWords[0]))
                        {
                            loc = 'T';
                        }
                        else if (isWordEq(FRY_FILE, LFile.TabWords[0]))
                        {
                            loc = 'F';
                        }
                        else if (isWordEq(CHOP_FILE, LFile.TabWords[0]))
                        {
                            loc = 'C';
                        }
                        else if (isWordEq(BOIL_FILE, LFile.TabWords[0]))
                        {
                            loc = 'B';
                        }
                        else if (isWordEq(MIX_FILE, LFile.TabWords[0]))
                        {
                            loc = 'M';
                        }
                        day3 = wordToInt(LFile.TabWords[1]);
                        hour3 = wordToInt(LFile.TabWords[2]);
                        min3 = wordToInt(LFile.TabWords[3]);
                        CreateTime(&pengolahan, day3, hour3, min3);
                        break;
                    case 5: /* Ukuran Makanan (mxn) */
                        Absis(size) = wordToInt(LFile.TabWords[0]);
                        Ordinat(size) = wordToInt(LFile.TabWords[1]);
                        break;
                    default:
                        break;
                    }
                    ADVNewline();
                }
                createMakanan(&M, id, name, exp, loc, delivery, size, pengolahan);
                insertFood(&g->listMakanan, M);
            }
            break;
        case 2: /* Config Resep */
            (&g->listResep)->elEff = wordToInt(LFile.TabWords[0]);
            for (int i = 0; i < (&g->listResep)->elEff; i++)
            {
                ADVNewline();
                LFile = readLineFile();

                Tree parent = newTreeNode(wordToInt(LFile.TabWords[0]));
                int bykChild = wordToInt(LFile.TabWords[1]);
                for (int j = 0; j < bykChild; j++)
                {
                    addChild(&parent, newTreeNode(wordToInt(LFile.TabWords[2 + j])));
                }
                (&g->listResep)->list[i] = parent;
                for (int j = 0; j < i; j++)
                {
                    tambahBahan(&parent, (&g->listResep)->list[j]);
                    tambahBahan(&(&g->listResep)->list[j], parent);
                }
            }
            break;
        case 3: /* Config Peta */;
            // Map MapGame;
            CreateMap((&g->map), wordToInt(LFile.TabWords[0]), wordToInt(LFile.TabWords[1]));
            POINT M;

            for (int i = 0; i < (&(&g->map)->Peta)->rowEff; i++)
            {
                ADVNewline();
                LFile = readLineFile();
                for (int j = 0; j < (&(&g->map)->Peta)->colEff; j++)
                {
                    CreatePoint(&M, i, j);
                    (&(&g->map)->Peta)->mem[(i)][(j)] = LFile.TabWords[0].TabWord[j];

                    if ((&(&g->map)->Peta)->mem[(i)][(j)] == 'S')
                    {
                        gantiLokasi(sim, M);
                        (&(&g->map)->Peta)->mem[(i)][(j)] = '#';
                    }
                    else if ((&(&g->map)->Peta)->mem[(i)][(j)] == 'T')
                    {
                        insertPoint(&(&g->map)->T_Map, M);
                    }
                    else if ((&(&g->map)->Peta)->mem[(i)][(j)] == 'M')
                    {
                        insertPoint(&(&g->map)->M_Map, M);
                    }
                    else if ((&(&g->map)->Peta)->mem[(i)][(j)] == 'F')
                    {
                        insertPoint(&(&g->map)->F_Map, M);
                    }
                    else if ((&(&g->map)->Peta)->mem[(i)][(j)] == 'C')
                    {
                        insertPoint(&(&g->map)->C_Map, M);
                    }
                    else if ((&(&g->map)->Peta)->mem[(i)][(j)] == 'B')
                    {
                        insertPoint(&(&g->map)->B_Map, M);
                    }
                    else if ((&(&g->map)->Peta)->mem[(i)][(j)] == 'X')
                    {
                        insertPoint(&(&g->map)->X_Map, M);
                    }
                }
            }
            break;
        default:
            break;
        }
    }
}

void help()
{
    sprintCyan("\n      \xB2\xB2\xB2\xB2\xB2\xB2\xB2 LIST COMMAND \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("========================================\n");
    printf("No  Command                             \n"); // TABLE TITLES !
    printf("========================================\n");
    printf("%2d  MOVE X (X: NORTH/ SOUTH/ WEST/ EAST)\n", 1);
    printf("%2d  BUY\n", 2);
    printf("%2d  FRY\n", 3);
    printf("%2d  CHOP\n", 4);
    printf("%2d  BOIL\n", 5);
    printf("%2d  MIX\n", 6);
    printf("%2d  WAIT X Y (X: jam, Y: menit)\n", 7);
    printf("%2d  INVENTORY\n", 8);
    printf("%2d  DELIVERY\n", 9);
    printf("%2d  CATALOG\n", 10);
    printf("%2d  COOKBOOK\n", 11);
    printf("%2d  UNDO\n", 12);
    printf("%2d  REDO\n", 13);
    printf("%2d  MASUKKULKAS X Y (X: index makanan di Inventory, Y: nomor yang ingin dipakai)\n", 14);
    printf("%2d  KELUARKULKAS X (X: ID makanan di kulkas)\n", 15);
    printf("%2d  KULKAS\n", 16);
    printf("%2d  REKOMENDASI\n", 17);
    printf("%2d  HELP\n", 18);
    printf("%2d  EXIT\n", 19);
}

int select(int min, int max)
{
    char minChar = min + '0';
    char maxChar = max + '0';
    sprintBlue("\nKirim 0 untuk exit.\n\nEnter Command: \n");
    printf("> ");
    ListWord L;
    createListWord(&L);
    L = readLine();
    while (L.Length != 1 || wordToInt(L.TabWords[0]) == -999 || (wordToInt(L.TabWords[0]) < min || wordToInt(L.TabWords[0]) > max))
    {
        if (wordToInt(L.TabWords[0]) == 0 && L.Length == 1)
        {
            return 0;
        }
        else
        {
            sprintRed("\nInput invalid. Silahkan masukkan angka (");
            printRed(minChar);
            printRed('-');
            printRed(maxChar);
            sprintRed(") atau angka 0 untuk exit!");
            printf("\n");
            printf("> ");
            L = readLine();
        }
    }
    return wordToInt(L.TabWords[0]);
}

void tambahBahan(Tree *p, Tree l)
{
    if ((*p)->childEff == 0)
    {
        if ((*p)->info == l->info)
        {
            (*p)->childEff = l->childEff;
            for (int j = 0; j < (*p)->childEff; j++)
            {
                (*p)->children[j] = l->children[j];
            }
        }
    }
    else
    {
        for (int i = 0; i < (*p)->childEff; i++)
        {
            tambahBahan(&(*p)->children[i], l);
        }
    }
}

void printCookBook(ListStatikT listResep, ListStatikM listMakanan)
{
    Makanan display;
    Tree resep;
    sprintCyan("\n        \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 COOKBOOK \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("===========================================\n");
    printf("No  Resep                                  \n"); // TABLE TITLES !
    printf("===========================================\n");
    for (int i = 0; i < listResep.elEff; i++)
    {
        resep = listResep.list[i];
        display = getMakananFromId(resep->info, listMakanan);
        printf("%2d  %s\n", i + 1, display.name);
        printf("   ");
        if (display.location == 'B')
        {
            printf(" BOIL");
        }
        else if (display.location == 'F')
        {
            printf(" FRY");
        }
        else if (display.location == 'C')
        {
            printf(" CHOP");
        }
        else if (display.location == 'M')
        {
            printf(" MIX");
        }
        for (int j = 0; j < resep->childEff; j++)
        {
            printf(" - %s", getMakananFromId(resep->children[j]->info, listMakanan).name);
        }
        printf("\n");
    }
}

int getUrutanFromListMakanan(ListStatikM listMakanan, int idMakanan)
{
    int urutan;
    for (int i = 0; i < listLengthStatikM(listMakanan); i++)
    {
        if (listMakanan.contents[i].id == idMakanan)
        {
            urutan = i;
            break;
        }
    }
    return urutan;
}

boolean apakahBisa(Tree t, Set s, ListStatikM listMakanan)
{
    boolean bisa;
    if (t->childEff == 0)
    {
        bisa = s.contents[getUrutanFromListMakanan(listMakanan, t->info)] == 1;
    }
    else
    {
        if (s.contents[getUrutanFromListMakanan(listMakanan, t->info)] == 1)
        {
            bisa = true;
        }
        else
        {
            bisa = true;
            for (int i = 0; i < t->childEff; i++)
            {
                bisa = apakahBisa(t->children[i], s, listMakanan);
                if (bisa == false)
                {
                    break;
                }
            }
        }
        return bisa;
    }
}

void rekomendasiMakanan(ListStatikM listMakanan, PrioQueue listInvenMakanan, ListStatikT listResep)
{
    Set s;
    Address treeRekomen;
    Makanan rekomen;
    boolean bisa, splash;
    int i, num;

    createSet(&s);
    makeSetFromListMakanan(&s, listMakanan);
    makeSetFromInventory(&s, listMakanan, listInvenMakanan);
    num = 1;
    splash = true;

    for (i = 0; i < listResep.elEff; i++)
    {
        if (listResep.list[i]->childEff != 0)
        {
            bisa = true;
            treeRekomen = listResep.list[i];

            for (int j = 0; j < treeRekomen->childEff && bisa; j++)
            {
                if (!apakahBisa(treeRekomen->children[j], s, listMakanan))
                {
                    bisa = false;
                }
            }

            if (bisa && splash) {
                sprintCyan("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 REKOMENDASI \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
                printf("==============================\n");
                printf("No  Nama                      \n"); // TABLE TITLES !
                printf("==============================\n");
                splash = false;
            }

            if (bisa)
            {
                rekomen = getMakananFromId(treeRekomen->info, listMakanan);
                printf("%2d  %-20s\n", num, rekomen.name);
                num++;
            }
        }
    }

    if (num == 1) {
        sprintRed("\nTidak ada rekomendasi makanan dari bahan di Inventory. Cek COOKBOOK!\n");
    }
}

void exitGame()
{
    sprintGreen("\nTerima kasih telah menggunakan BNMO\n\n");
    exit(0);
}

void mengolahMakanan(Makanan makananOlah, Simulator *simulator, PrioQueue *delivery_list, ListDinMakanan *latest_notification, MatrixKulkas kulkas, Stack *stackUndo, Stack *stackRedo, Game *game, State *latest_state)
{
    Tree treeMakananOlah;
    infotype tmp;
    int id, idBahan[10];
    boolean bisa, ada;

    treeMakananOlah = getTreeFromMakanan(makananOlah, game->listResep);
    bisa = false;
    for (int i = 0; i < treeMakananOlah->childEff; i++)
    { // menelusuri tiap bahan makanan
        idBahan[i] = treeMakananOlah->children[i]->info;
        id = idBahan[i];
        ada = false;

        if (!IsEmptyPrioqueue(simulator->inventory))
        {
            for (int j = simulator->inventory.HEAD; j <= simulator->inventory.TAIL; j++)
            { // mencari apakah ada bahan pada inventori
                if (id == simulator->inventory.T[j].info.id)
                {
                    ada = true;
                }
            }
        }

        if (ada)
        {
            idBahan[i] = -1;
            if (i == 0)
            {
                bisa = true;
            }
        }
        else
        {
            bisa = false;
        }
    }

    if (bisa)
    { // jika bisa dibuat
        PrioQueue tempDelivery;
        CreateEmptyPrioqueue(&tempDelivery, 50);
        CopyQueue(delivery_list, &tempDelivery);
        Word TEMP = {"TEMP", 4};

        Simulator tempSimulator;
        POINT pTemp;
        PrioQueue pQueueTemp;
        CreatePoint(&pTemp, 0, 0);
        CreateEmptyPrioqueue(&pQueueTemp, 50);
        createSimulator(&tempSimulator, TEMP, pTemp, pQueueTemp);

        copySimulator(simulator, &tempSimulator);

        ListDinMakanan tempNotification;
        CreateListMakananDin(&tempNotification, 50);
        copyListDinMakanan(*latest_notification, &tempNotification);

        // masuk stack undo
        simulatorToState(tempSimulator, tempDelivery, game->currentTime, tempNotification, kulkas, latest_state);
        Push(stackUndo, *latest_state);

        // reset notifikasi
        dealocateListMakanan(latest_notification);
        CreateListMakananDin(latest_notification, 50);


        // change time
        TIME lama;
        lama = getMakananFromId(treeMakananOlah->info, game->listMakanan).pengolahan;
        game->currentTime = NextNMenit(game->currentTime, TIMEToMenit(lama));
        for (int i = 1; i <= TIMEToMenit(lama); i++)
        {
            PasstimeQueue(&simulator->inventory, 1, latest_notification);
            PassTimeDelivery(delivery_list, &simulator->inventory, 1, latest_notification);
        }
        // delete bahan
        for (int i = 0; i < treeMakananOlah->childEff; i++)
        {
            Delete(&simulator->inventory, treeMakananOlah->children[i]->info, &tmp);
        }

        tmp.info = makananOlah;
        tmp.time = makananOlah.expiry;

        Enqueue(&simulator->inventory, tmp);
        insertLastMakanan(latest_notification, tmp);
        printf("%s selesai dibuat dan sudah masuk inventory!\n", makananOlah.name);
        EmptyStack(stackRedo);
    }
    else
    { // jika tidak bisa dibuat
        printf("\nGagal membuat %s karena kamu tidak memiliki bahan berikut:\n", makananOlah.name);
        int j = 0;
        for (int i = 0; i < treeMakananOlah->childEff; i++)
        {
            if (idBahan[i] != -1)
            {
                j++;
                printf("  [%d] %s\n", j, getMakananFromId(idBahan[i], game->listMakanan).name);
            }
        }
    }
}