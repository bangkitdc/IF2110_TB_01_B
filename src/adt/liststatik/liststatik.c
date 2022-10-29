/* File: */

#include <stdio.h>
#include "liststatik.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong untuk list makanan */
void createLSMakanan(ListStatik *l){
    for (int i = 0; i < CAPACITY; i++){
        ID(ELMT(*l,i)) = MARK;
    }
}

/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
    int i = 0;
    while (ID(ELMT(l,i)) != MARK && i < CAPACITY){
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
    while (i < listLength(*l) && cek == false){
        if (ID(ELMT(*l,i)) == ID(food)) {
            ELMT(*l,i) = food;
            cek = true;
        }
        i += 1;
    }
    if (!cek) {
        ELMT(*l, listLength(*l)) = food;
    }
}

//ELMT(*l, listLength(*l)) = food;

/* Konstruktor : create List kosong untuk list resep */