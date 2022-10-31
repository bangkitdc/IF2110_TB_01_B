#include <stdio.h>
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

Word BUY_FILE = {"Buy", 3};
Word FRY_FILE = {"Fry", 3};
Word CHOP_FILE = {"Chop", 4};
Word BOIL_FILE = {"Boil", 4};
Word MIX_FILE = {"Mix", 3};

void startMenu(){
    int i;
    printf("\n");
    for (i = 0; i < 18; i ++) {
        printf("%s%d%c%d%c%d%c%s%s\n",
        "\x1B[38;2;",
        0, ';', (204 - i * 4), ';', (i * 9 + 90), 'm',
        bnmo[i],
        "\x1B[0m"
        );
    }
    printf("START/ EXIT: \n");
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
        CATALOG_COMMAND},
    11 };

    for (int i = 0; i < 11; i ++) {
        if (isWordEq(w, LCommand.TabWords[i])) {
            return i;
        }
    }
    return -1;
}

void inputConfigFile(Game *g, Word PATH, int type) {
    Word config;
    boolean flag = true;

    ListWord L;
    createListWord(&L);
    L = readLine();
    copyWord(L.TabWords[0], &config);
    char *dir = concatWord(PATH, config).TabWord;

    while (!(isFileExist(dir) && L.Length == 1)) {
        sprintRed("File tidak ditemukan. Coba nama file lain...\n");
        printf("Masukkan nama file: ");
        L = readLine();
        copyWord(L.TabWords[0], &config);
        dir = concatWord(PATH, config).TabWord;
    }
    
    STARTWORDFILE(dir);
    if (EndWord) {
        sprintRed("File yang dibaca kosong!");
    } else {
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
                    int id, day1, hour1, min1, day2, hour2, min2;
                    char *name;
                    TIME exp, delivery;
                    char loc;
                    for (j = 0; j < 5; j++) {
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
                                break;
                            // case 5:     /* Ukuran Makanan (mxn) */
                            //     m = wordToInt(LFile.TabWords[0]);
                            //     n = wordToInt(LFile.TabWords[1]);
                            //     break;
                            default:
                                break;
                        }
                        ADVNewline();
                    }
                    createMakanan(&M, id, name, exp, loc, delivery);
                    insertFood(&g->listMakanan, M);
                }
                break;
            case 2: /* Config Resep */
                // sementara disimpan di ListTree karena butuh list statik dengan tipe elemen tree
                ListStatikT listResep;
                CreateListTree(&listResep);
                listResep.elEff = wordToInt(LFile.TabWords[0]);
                for(int i=0;i<listResep.elEff;i++){
                    ADVNewline();
                    LFile = readLineFile();
                    
                    Tree parent = newTreeNode(wordToInt(LFile.TabWords[0]));
                    int bykChild = wordToInt(LFile.TabWords[1]);
                    for(int j=0;j<bykChild;j++){
                        addChild(&parent, wordToInt(LFile.TabWords[2+j]));
                    }
                    listResep.list[i] = parent;
                    // printPreorder(parent);
                    // printf("\n");
                }
                (*g).listResep = listResep;
                break;
            case 3: /* Config Peta */
                Map MapGame;
                CreateMap(&MapGame, wordToInt(LFile.TabWords[0]), wordToInt(LFile.TabWords[1]));
                //ROW_EFF(PETA(MapGame)) = wordToInt(LFile.TabWords[0]);
                //COL_EFF(PETA(MapGame)) = wordToInt(LFile.TabWords[1]);
                POINT M;
                ListStatikP TM, MM, FM, CM,BM;
                CreatePoint(&M, i, j);
                createLSPoint (&TM);
                createLSPoint (&MM);
                createLSPoint (&FM);
                createLSPoint (&CM);
                createLSPoint (&BM);
                for (int i=0; i< ROW_EFF(PETA(MapGame)); i++) {
                    ADVNewline();
                    LFile = readLineFile();
                    for (int j=0; j< COL_EFF(PETA(MapGame)); j++) {
                        ELMT_MATRIX(PETA(MapGame),i,j) = LFile.TabWords[0].TabWord[j];
                        if (ELMT_MATRIX(PETA(MapGame),i,j) == 'S') {
                            SMap(MapGame) = M;
                        } else if (ELMT_MATRIX(PETA(MapGame),i,j) == 'T') {
                            insertPoint(&TM,M);
                        } else if (ELMT_MATRIX(PETA(MapGame),i,j) == 'M') {
                            insertPoint(&MM,M);
                        } else if (ELMT_MATRIX(PETA(MapGame),i,j) == 'F') {
                            insertPoint(&FM,M);
                        } else if (ELMT_MATRIX(PETA(MapGame),i,j) == 'C') {
                            insertPoint(&CM,M);
                        } else if (ELMT_MATRIX(PETA(MapGame),i,j) == 'B') {
                            insertPoint(&BM,M);
                        }
                    }
                }
                TMap(MapGame) = TM;
                MMap(MapGame) = MM;
                FMap(MapGame) = FM;
                CMap(MapGame) = CM;
                BMap(MapGame) = BM;
                (*g).map = MapGame;
                break;
            default:
                break;
        }
    }
}

void exitGame() {
    sprintGreen("Terima kasih telah menggunakan BNMO\n");
    exit(0);
}