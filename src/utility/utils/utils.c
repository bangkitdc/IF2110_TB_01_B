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

Word START_WORD = {"START", 5};
Word EXIT_WORD = {"EXIT", 4};

Word BUY_WORD = {"Buy", 3};
Word FRY_WORD = {"Fry", 3};
Word CHOP_WORD = {"Chop", 4};
Word BOIL_WORD = {"Boil", 4};
Word MIX_WORD = {"Mix", 3};

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
    if (isWordEq(w, START_WORD)) {
        return 1;
    } else if (isWordEq(w, EXIT_WORD)) {
        return 2;
    } else {
        return -1;
    }
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
                                if (isWordEq(BUY_WORD, LFile.TabWords[0])) {
                                    loc = 'T';
                                } else if (isWordEq(FRY_WORD, LFile.TabWords[0])) {
                                    loc = 'F';
                                } else if (isWordEq(CHOP_WORD, LFile.TabWords[0])) {
                                    loc = 'C';
                                } else if (isWordEq(BOIL_WORD, LFile.TabWords[0])) {
                                    loc = 'B';
                                } else if (isWordEq(MIX_WORD, LFile.TabWords[0])) {
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
                ListTree listResep;
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
                break;
            case 3: /* Config Peta */

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