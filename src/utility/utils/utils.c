#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "../../include/boolean.h"


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
Word MASUKKULKAS_COMMAND = {"MASUKKULKAS", 11};
Word KELUARKULKAS_COMMAND = {"KELUARKULKAS", 12};
Word UNDO_COMMAND = {"UNDO", 4};
Word REDO_COMMAND = {"REDO", 4};

Word BUY_FILE = {"Buy", 3};
Word FRY_FILE = {"Fry", 3};
Word CHOP_FILE = {"Chop", 4};
Word BOIL_FILE = {"Boil", 4};
Word MIX_FILE = {"Mix", 3};

void startMenu(){
    int i;
    for (i = 0; i < 18; i ++) {
        printf("%s%d%c%d%c%d%c%s%s\n",
        "\x1B[38;2;",
        0, ';', (204 - i * 4), ';', (i * 9 + 90), 'm',
        bnmo[i],
        "\x1B[0m"
        );
    }
    printf("\n");
    sprintCyan("======= List Command =======\n");
    sprintGreen("[1] START \n");
    sprintRed("[2] EXIT \n");
}

int startInput(Word w) {
    if (isWordEq(w, START_COMMAND)) {
        return 1;
    } else if (isWordEq(w, EXIT_COMMAND)) {
        return 2;
    } else {
        return -1;
    }
}

int MenuInput(Word w) {
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
        MASUKKULKAS_COMMAND,
        KELUARKULKAS_COMMAND,
        UNDO_COMMAND,
        REDO_COMMAND},
    17 };

    for (int i = 0; i < 17; i ++) {
        if (isWordEq(w, LCommand.TabWords[i])) {
            return i;
        }
    }
    return -1;
}

void inputConfigFile(Game *g,Simulator *sim, char *PATH, int type) {
    STARTWORDFILE(PATH);

    if (!EndWord) { 
        ListWord LFile;
        createListWord(&LFile);

        LFile = readLineFile();

        switch (type) {
            case 1: /* Config Makanan */;
                int n;
                n = wordToInt(LFile.TabWords[0]); /* Jumlah Makanan */

                ADVNewline();
                int i, j, k;
                for (i = 0; i < n; i++) {
                    Makanan M;
                    int id, day1, hour1, min1, day2, hour2, min2, day3, hour3, min3;
                    char *name;
                    TIME exp, delivery, pengolahan;
                    char loc;
                    POINT size;
                    for (j = 0; j < 6; j++) {
                        LFile = readLineFile();
                        switch (j) {
                            case 0:     /* ID */
                                id = wordToInt(LFile.TabWords[0]);
                                break;  /* Nama Makanan */
                            case 1:
                                name = ListWordToString(LFile);
                                break;
                            case 2:     /* Waktu Expired */
                                day1 = wordToInt(LFile.TabWords[0]);
                                hour1 = wordToInt(LFile.TabWords[1]);
                                min1 = wordToInt(LFile.TabWords[2]);
                                CreateTime (&exp, day1, hour1, min1);
                                break;
                            case 3:     /* Waktu Delivery */
                                day2 = wordToInt(LFile.TabWords[0]);
                                hour2 = wordToInt(LFile.TabWords[1]);
                                min2 = wordToInt(LFile.TabWords[2]);
                                CreateTime(&delivery, day2, hour2, min2);
                                break;
                            case 4:     /* Lokasi Aksi */
                                if (isWordEq(BUY_FILE, LFile.TabWords[0])) {
                                    loc = 'T';
                                } else if (isWordEq(FRY_FILE, LFile.TabWords[0])) {
                                    loc = 'F';
                                } else if (isWordEq(CHOP_FILE, LFile.TabWords[0])) {
                                    loc = 'C';
                                } else if (isWordEq(BOIL_FILE, LFile.TabWords[0])) {
                                    loc = 'B';
                                } else if (isWordEq(MIX_FILE, LFile.TabWords[0])) {
                                    loc = 'M';
                                }
                                day3 = wordToInt(LFile.TabWords[1]);
                                hour3 = wordToInt(LFile.TabWords[2]);
                                min3 = wordToInt(LFile.TabWords[3]);
                                CreateTime(&pengolahan, day3, hour3, min3);
                                break;
                            case 5:     /* Ukuran Makanan (mxn) */
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
                /* Dicoba langsung akses ke game (BANGKIT) */
                (&g->listResep)->elEff = wordToInt(LFile.TabWords[0]);
                for(int i=0;i<(&g->listResep)->elEff;i++){
                    ADVNewline();
                    LFile = readLineFile();
                    
                    Tree parent = newTreeNode(wordToInt(LFile.TabWords[0]));
                    int bykChild = wordToInt(LFile.TabWords[1]);
                    for(int j=0;j<bykChild;j++){
                        addChild(&parent, newTreeNode(wordToInt(LFile.TabWords[2+j])));
                    }
                    (&g->listResep)->list[i] = parent;
                    for(int j=0;j<i;j++){
                        tambahBahan(&parent, (&g->listResep)->list[j]);
                        tambahBahan(&(&g->listResep)->list[j], parent);
                    }
                }
                // for (int i = 0; i < (&g->listResep)->elEff;i++ ) {
                //     printPreorder(g->listResep.list[i]);
                //     printf("\n");
                // }
                break;
            case 3: /* Config Peta */;
                //Map MapGame;
                CreateMap((&g->map), wordToInt(LFile.TabWords[0]), wordToInt(LFile.TabWords[1]));
                POINT M;

                for (int i=0; i< (&(&g->map)->Peta)->rowEff; i++) {
                    ADVNewline();
                    LFile = readLineFile();
                    for (int j=0; j< (&(&g->map)->Peta)->colEff; j++) {
                        CreatePoint(&M, i, j);
                        (&(&g->map)->Peta)->mem[(i)][(j)] = LFile.TabWords[0].TabWord[j];

                        if ((&(&g->map)->Peta)->mem[(i)][(j)] == 'S') {
                            gantiLokasi(sim,M);
                            (&(&g->map)->Peta)->mem[(i)][(j)] = '#';
                        } else if ((&(&g->map)->Peta)->mem[(i)][(j)] == 'T') {
                            insertPoint(&(&g->map)->T_Map,M);
                        } else if ((&(&g->map)->Peta)->mem[(i)][(j)] == 'M') {
                            insertPoint(&(&g->map)->M_Map,M);
                        } else if ((&(&g->map)->Peta)->mem[(i)][(j)] == 'F') {
                            insertPoint(&(&g->map)->F_Map,M);
                        } else if ((&(&g->map)->Peta)->mem[(i)][(j)] == 'C') {
                            insertPoint(&(&g->map)->C_Map,M);
                        } else if ((&(&g->map)->Peta)->mem[(i)][(j)] == 'B') {
                            insertPoint(&(&g->map)->B_Map,M);
                        } else if ((&(&g->map)->Peta)->mem[(i)][(j)] == 'X') {
                            insertPoint(&(&g->map)->X_Map,M);
                        }
                    }
                }
                break;
            default:
                break;
        }
    }
}

void help() {
    sprintCyan("\n============== List Command ==============\n");
    printf("  [1]  MOVE X (X: NORTH/ SOUTH/ WEST/ EAST)\n");
    printf("  [2]  BUY\n");
    printf("  [3]  FRY\n");
    printf("  [4]  CHOP\n");
    printf("  [5]  BOIL\n");
    printf("  [6]  MIX\n");
    printf("  [7]  WAIT X Y (X: jam, Y: menit)\n");
    printf("  [8]  INVENTORY\n");
    printf("  [9]  DELIVERY\n");
    printf("  [10] CATALOG\n");
    printf("  [11] COOKBOOK\n");
    printf("  [12] UNDO\n");
    printf("  [13] REDO\n");
    printf("  [14] MASUKKULKAS\n");
    printf("  [15] KELUARKULKAS\n");
    printf("  [16] HELP\n");
    printf("  [17] EXIT\n");
}

void tambahBahan(Tree *p, Tree l){
    Tree parent;
    for(int i=0;i<(*p)->childEff;i++){
        parent = (*p)->children[i];
        if(parent->info == l->info){
            parent->childEff = l->childEff;
            for(int j=0;j<parent->childEff;j++){
                parent->children[j] = l->children[j];
            }
        }
    }
}

void printCookBook(ListStatikT listResep, ListStatikM listMakanan){
    Makanan display;
    Tree resep;
    for(int i=0;i<listResep.elEff;i++){
        resep = listResep.list[i];
        display = getMakananFromId(resep->info, listMakanan);
        printf("%d. %s\n", i+1, display.name);
        printf("   ");
        if(display.location == 'B'){
            printf("BOIL");
        }else if(display.location == 'F'){
            printf("FRY");
        }else if(display.location == 'C'){
            printf("CHOP");
        }else if(display.location == 'M'){
            printf("MIX");
        }
        for(int j=0;j<resep->childEff;j++){
            printf(" - %s", getMakananFromId(resep->children[j]->info, listMakanan).name);
        }
        printf("\n");
    }
}

void exitGame() {
    sprintGreen("\nTerima kasih telah menggunakan BNMO\n\n");
    exit(0);
}