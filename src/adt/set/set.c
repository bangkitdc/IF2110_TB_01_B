/* File: */

#include <stdio.h>
#include "set.h"
#include "../../utility/color/color.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong untuk set */
void createSet(Set *s) {
    for (int i = 0; i < CAPACITY_SET; i++){
        (ELMT_SET(*s,i)) = MARKSET;
    }
}

/* *** Banyaknya elemen *** */
int LengthSet(Set s) {
    int i = 0;
    while (ELMT_SET(s,i) != MARKSET && i < CAPACITY_SET){
        i+=1;
    }
    return i;
}

/* isAnggota: Memeriksa apakah indexmakanan merupakan anggota set s */
boolean isAnggota(int indexmakanan, Set s) {
    return (ELMT_SET(s, indexmakanan) == 1);
}

/* isSubset: Memeriksa apakah set s merupakan subset dari set t */
boolean isSubset(Set s, Set t) {
    boolean same = true;
    int i = 0;
    while (i < LengthSet(s) && same) {
        if ((ELMT_SET(s, i) == 1) && (!isAnggota(i, t))) {
            same = false;
        }
        i+=1;
    }
    return same;
}

void makeSetFromListMakanan(Set *s, ListStatikM daftarMakanan) {
/* I.S. s terdefinisi */
/* F.S. Meng-assign elemen-elemen pada set s dengan 0 pada daftarMakanan */
    for (int i = 0; i < listLengthStatikM(daftarMakanan); i++) {
        ELMT_SET(*s, i) = 0;
    }
}

void makeSetFromInventory(Set *s, ListStatikM daftarMakanan, ListDinMakanan inventory) {
/* I.S. s terdefinisi */
/* F.S. Meng-assign elemen tertentu pada set s dengan 1 jika makanan yang berkorespondensi dengan indeks daftarMakanan
tersedia di inventory */
    for (int i = 0; i < listLengthStatikM(daftarMakanan); i++) {
        for (int j = 0; j < listMakananLengthDinamis(inventory); j++) {
            if ((ID(Info(ELMT_LISTDINAMIS_Makanan(inventory, j)))) == ID(ELMT_LISTSTATIKM(daftarMakanan, i))) {
                ELMT_SET(*s, i) = 1;
            }
        }
    }
}
