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
    printf("> ");
}

int startInput(Word w) {
    Word START = {"START", 5};
    Word EXIT = {"EXIT", 4};

    if (isWordEq(w, START)) {
        return 1;
    } else if (isWordEq(w, EXIT)) {
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
            case 1: /* Config Makanan */
                int n = wordToInt(LFile.TabWords[0]); /* Jumlah Makanan */
                /* INPUT JUMLAH MAKANAN DISNI
                pake parameter g
                */

                ADVNewline();
                int i, j, k;
                for (i = 0; i < n; i++) {
                    Makanan M;
                    int id;
                    char *name;
                    TIME exp;
                    char loc;
                    TIME delivery;
                    for (j = 0; j < 5; j++) {
                        LFile = readLineFile();
                        switch (j) {
                            case 0:     /* ID */
                                id = wordToInt(LFile.TabWords[0]);
                                break;  /* Nama Makanan */
                            case 1:
                                name = 
                                break;
                            case 2:     /* Waktu Expired */
                                
                                break;
                            case 3:     /* Waktu Delivery */

                                break;
                            case 4:     /* Lokasi Aksi */

                                break;
                            default:
                                break;
                        }
                        for (k = 0; k < LFile.Length; k++) {
                            displayWord(LFile.TabWords[k]);
                        }
                        ADVNewline();
                    }
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
    printGreen("Terima kasih telah menggunakan BNMO\n");
    exit(0);
}