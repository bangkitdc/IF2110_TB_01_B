/* File: */

#include <stdio.h>
#include "liststatik.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong untuk list makanan */
void createLSMakanan(ListStatik *l){
    for (int i = 0; i < CAPACITY_LISTSTATIK; i++){
        ID(ELMT_LISTSTATIK(*l,i)) = MARKSTATIK;
    }
}

/* *** Banyaknya elemen *** */
int listLengthStatik(ListStatik l){
    int i = 0;
    while (ID(ELMT_LISTSTATIK(l,i)) != MARKSTATIK && i < CAPACITY_LISTSTATIK){
        i+=1;
    }
    return i;
}

/* *** Menambahkan elemen terakhir *** */
void insertFood(ListStatik *l, Makanan food){
/* Proses: Menambahkan food ke dalam list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. food adalah elemen terakhir l yang baru jika id nya tidak sama 
dengan id makanan yang sudah ada dalam list sebelumnya. Jika Id nya sama dengan makanan sebelumnya,
maka food akan menimpa makanan yang sudah didefinisikan sebelumnya. */
    boolean cek = false;
    int i = 0;
    while (i < listLengthStatik(*l) && cek == false){
        if (ID(ELMT_LISTSTATIK(*l,i)) == ID(food)) {
            ELMT_LISTSTATIK(*l,i) = food;
            cek = true;
        }
        i += 1;
    }
    if (!cek) {
        ELMT_LISTSTATIK(*l, listLengthStatik(*l)) = food;
    }
}

void printCatalog(ListStatik l) {
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    printf("List Makanan\n");
    printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)\n");

    if (listLengthStatik(l) > 0) {
        for (i = 0; i < listLengthStatik(l); i ++) {
            Makanan temp = ELMT_LISTSTATIK(l, i);
            printf("  %d. %s - %d:%d:%d - %c - %d:%d:%d\n", i + 1,NAME(temp), EXP(temp).DD, EXP(temp).HH, EXP(temp).MM, LOC(temp), DELIVERY(temp).DD, DELIVERY(temp).HH, DELIVERY(temp).MM);
        }
    }
}

//ELMT_LISTSTATIK(*l, listLengthStatik(*l)) = food;

/* Konstruktor : create List kosong untuk list resep */