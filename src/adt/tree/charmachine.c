/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "charmachine.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START() {
       /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
                 Jika currentChar = MARK maka EOP akan menyala (true) */

       /* ALGORITMA */
       pita = stdin;
       ADV();
}

void ADV() {
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentChar, currentChar != MARK
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
                 currentChar mungkin = MARK.
                 Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* ALGORITMA */
       retval = fscanf(pita, "%c", &currentChar);
       EOP = (currentChar == MARK);
       // if (EOP)
       // {
       //        fclose(pita);
       // }
}

void STARTFILE(char *dir) {
       /* Mesin siap dioperasikan. Pita dibaca dari file */
       
       /* ALGORITMA*/
       if (isFileExist(dir)) {
              pita = fopen(dir, "r");
              ADV();
       }
}

boolean isFileExist(char *dir) {
       /* Menghasilkan true jika file dengan path dir bisa dibuka*/
       
       /* ALGORITMA */
       return (fopen(dir, "r") != NULL);
}

void closeChar() {
       currentChar = '\0';
       fclose(pita);
       EOP = true;
       pita = NULL;
}