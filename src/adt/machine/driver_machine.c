#include <stdio.h>
#include "wordmachine.h"

/* Driver input File */

int main() {
    printf("Masukkan nama file: ");

    STARTWORD();

    char *dir = currentWord.TabWord;

    while (!isFileExist(dir)) {
        printf("File tidak ditemukan. Coba nama file lain...\n");
        printf("Masukkan nama file: ");
        STARTWORD();
        dir = currentWord.TabWord;
    }

    STARTWORDFILE(dir);
    if (EndWord) {
        printf("Pita file kosong");
    } else {
        ListWord L;
        createListWord(&L);

        L = readLineFile();

        int n = wordToInt(L.TabWords[0]);
        printf("%d\n", n);

        ADVNewline();

        for (int i = 0; i < n; i ++) {
            printf("(%d)\n", i + 1);
            for (int j = 0; j < 5; j ++)  {
                L = readLineFile();
                for (int k = 0; k < L.Length; k ++) {
                    displayWord(L.TabWords[k]);
                    printf(" ");
                }
                ADVNewline();
            }
            printf("\n");
        }
    }

    return 0;
}