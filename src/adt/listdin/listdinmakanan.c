/* File: */

#include <stdio.h>
#include "listdinmakanan.h"
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListMakananDin(ListDinMakanan *l, int capacity) {
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    CAPACITY_LISTDINAMIS_Makanan(*l) = capacity;
    NEFF_Makanan(*l) = 0;
    BUFFER_Makanan(*l) = malloc (capacity*sizeof(ElTypeMakanan));
}

void dealocateListMakanan(ListDinMakanan *l) {
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY_LISTDINAMIS_Makanan(l)=0; NEFF_Makanan(l)=0 */
    CAPACITY_LISTDINAMIS_Makanan(*l) = 0;
    NEFF_Makanan(*l) = 0;
    free(BUFFER_Makanan(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listMakananLengthDinamis(ListDinMakanan l) {
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
    return NEFF_Makanan(l);
}

/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdxS(ListDinMakanan l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    return 0;
}

IdxType getLastIdxS(ListDinMakanan l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return NEFF_Makanan(l)-1;
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void printListMakanan(ListDinMakanan l) {
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

}



/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastMakanan(ListDinMakanan *l, ElTypeMakanan val) {
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    ELMT_LISTDINAMIS_Makanan(*l, NEFF_Makanan(*l)) = val;
    NEFF_Makanan(*l) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastMakanan(ListDinMakanan *l, ElTypeMakanan *val) {
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = ELMT_LISTDINAMIS_Makanan(*l,listMakananLengthDinamis(*l)-1);
    NEFF_Makanan(*l) -= 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListMakanan(ListDinMakanan *l, int num) {
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    CAPACITY_LISTDINAMIS_Makanan(*l) += num;
    BUFFER_Makanan(*l) = realloc (BUFFER_Makanan(*l), CAPACITY_LISTDINAMIS_Makanan(*l) * sizeof(ElTypeMakanan));
}
