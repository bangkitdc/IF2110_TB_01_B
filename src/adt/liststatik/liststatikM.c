/* File: */

#include <stdio.h>
#include "liststatikM.h"

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
    printf("List Makanan\n");
    printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)\n");

    if (listLengthStatikM(l) > 0) {
        for (i = 0; i < listLengthStatikM(l); i ++) {
            Makanan temp = ELMT_LISTSTATIKM(l, i);
            printf("  %d. %s - %d:%d:%d - %c - %d:%d:%d\n", i + 1,NAME(temp), EXP(temp).DD, EXP(temp).HH, EXP(temp).MM, LOC(temp), DELIVERY(temp).DD, DELIVERY(temp).HH, DELIVERY(temp).MM);
        }
    }
}

//ELMT_LISTSTATIKM(*l, listLengthStatikM(*l)) = food;

/* Konstruktor : create List kosong untuk list resep */