/* File: */

#include <stdio.h>
#include "liststatik.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong untuk list makanan */
void createLSMakanan(ListStatik *l){
    for (int i = 0; i < CAPACITY; i++){
        ELMT(*l,i) = MARK;
    }
}

/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
    int i = 0;
    while (ELMT(l,i) != MARK && i < CAPACITY){
        i+=1;
    }
    return i;
}

/* *** Menambahkan makanan ke elemen terakhir *** */
void insertLast(ListStatik *l, Makanan food){
/* I.S. List l boleh kosong, tetapi tidak penuh */
    ELMT(*l, listLength(*l)) = food;
}

/* Konstruktor : create List kosong untuk list resep */