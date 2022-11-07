/* File: */

#include <stdio.h>
#include "liststatikM.h"
#include "../../utility/color/color.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong untuk list makanan */
void createLSMakanan(ListStatikM *l){
    for (int i = 0; i < CAPACITY_LISTSTATIKM; i++){
        ID(ELMT_LISTSTATIKM(*l,i)) = MARKSTATIK;
    }
}

/* *** Banyaknya elemen *** */
int listLengthStatikM(ListStatikM l){
    int i = 0;
    while (ID(ELMT_LISTSTATIKM(l,i)) != MARKSTATIK && i < CAPACITY_LISTSTATIKM){
        i+=1;
    }
    return i;
}

/* *** Menambahkan elemen terakhir *** */
void insertFood(ListStatikM *l, Makanan food){
/* Proses: Menambahkan food ke dalam list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. food adalah elemen terakhir l yang baru jika id nya tidak sama 
dengan id makanan yang sudah ada dalam list sebelumnya. Jika Id nya sama dengan makanan sebelumnya,
maka food akan menimpa makanan yang sudah didefinisikan sebelumnya. */
    boolean cek = false;
    int i = 0;
    while (i < listLengthStatikM(*l) && cek == false){
        if (ID(ELMT_LISTSTATIKM(*l,i)) == ID(food)) {
            ELMT_LISTSTATIKM(*l,i) = food;
            cek = true;
        }
        i += 1;
    }
    if (!cek) {
        ELMT_LISTSTATIKM(*l, listLengthStatikM(*l)) = food;
    }
}

void printCatalog(ListStatikM l) {
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    sprintCyan("\n============== List Makanan ==============\n");
    printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time - size)\n");

    if (listLengthStatikM(l) > 0) {
        for (i = 0; i < listLengthStatikM(l); i ++) {
            Makanan temp = ELMT_LISTSTATIKM(l, i);
            printf("  [%d] %s - ", i + 1, NAME(temp));
            TulisTIME2(EXP(temp));
            switch (LOC(temp)) {
                case 'T':
                    printf(" - BUY - ");
                    break;
                case 'F':
                    printf(" - FRY (");
                    TulisTIME2(PENGOLAHAN(temp));
                    printf(") - ");
                    break;
                case 'M':
                    printf(" - MIX (");
                    TulisTIME2(PENGOLAHAN(temp));
                    printf(") - ");
                    break;
                case 'C':
                    printf(" - CHOP (");
                    TulisTIME2(PENGOLAHAN(temp));
                    printf(") - ");
                    break;
                case 'B':
                    printf(" - BOIL (");
                    TulisTIME2(PENGOLAHAN(temp));
                    printf(") - ");
                    break;
                default:
                    break;
            }
            if (TIMEToMenit(DELIVERY(temp)) == 0) {
                printf("0");
            } else {
                TulisTIME2(DELIVERY(temp));
            }
            printf(" - (%d x %d)", Absis(SIZE(temp)), Ordinat(SIZE(temp)));
            printf("\n");
        }

        // https://stackoverflow.com/questions/39025074/c-program-how-to-print-in-table-format-alignment
        // for (int i = 0; i < listLengthStatikM(l); i ++) {
        //     Makanan temp = ELMT_LISTSTATIKM(l, i);
        //     printf("%-10d\t\t %-12s\t\t %8c\t %8d\n\n", ID(temp), NAME(temp), LOC(temp), Absis(SIZE(temp)));
        // }
    } else {
        sprintRed("\nCatalog kosong :(\n");
    }
}

//ELMT_LISTSTATIKM(*l, listLengthStatikM(*l)) = food;

/* Konstruktor : create List kosong untuk list resep */