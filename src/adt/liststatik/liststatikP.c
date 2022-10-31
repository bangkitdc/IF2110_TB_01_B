/* File: */

#include <stdio.h>
#include "liststatikP.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong untuk list makanan */
void createLSPoint(ListStatikP *l){
    for (int i=0; i<CAPACITY_LISTSTATIK; i++){
        Absis(ELMT_LISTSTATIK(*l,i)) = MARKSTATIK;
        Ordinat(ELMT_LISTSTATIK(*l,i)) = MARKSTATIK;
    }
}

/* *** Banyaknya elemen *** */
int listLengthStatikP(ListStatikP l){
    int i = 0;
    while (Absis(ELMT_LISTSTATIK(l,i)) == MARKSTATIK || Ordinat(ELMT_LISTSTATIK(l,i)) == MARKSTATIK) {
        i += 1;
    }
    return i;
}

/* *** Menambahkan elemen terakhir *** */
void insertPoint(ListStatikP *l, POINT p){
/* Proses: Menambahkan food ke dalam list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. food adalah elemen terakhir l yang baru jika id nya tidak sama 
dengan id makanan yang sudah ada dalam list sebelumnya. Jika Id nya sama dengan makanan sebelumnya,
maka food akan menimpa makanan yang sudah didefinisikan sebelumnya. */
    Absis(ELMT_LISTSTATIK(*l, listLengthP(*l))) = Absis(p);
    Ordinat(ELMT_LISTSTATIK(*l, listLengthP(*l))) = Ordinat(p);
}