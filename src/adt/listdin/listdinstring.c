/* File: */

#include <stdio.h>
#include "listdinstring.h"
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListStringDin(ListDinString *l, int capacity) {
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    CAPACITY_LISTDINAMIS_String(*l) = capacity;
    NEFF_String(*l) = 0;
    BUFFER_String(*l) = malloc (capacity*sizeof(ElTypeString));
}

void dealocateListString(ListDinString *l) {
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY_LISTDINAMIS_String(l)=0; NEFF_String(l)=0 */
    CAPACITY_LISTDINAMIS_String(*l) = 0;
    NEFF_String(*l) = 0;
    free(BUFFER_String(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listStringLengthDinamis(ListDinString l) {
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
    return NEFF_String(l);
}

/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdxS(ListDinString l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    return 0;
}

IdxType getLastIdxS(ListDinString l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return NEFF_String(l)-1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListStringDinamis(ListDinString l, IdxType i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (i >= 0 && i < CAPACITY_LISTDINAMIS_String(l));
}

boolean isIdxEffListStringDinamis(ListDinString l, IdxType i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF_String(l) */
    return (i >= 0 && i < NEFF_String(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isStringEmpty(ListDinString l) {
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    return (NEFF_String(l) == 0);
}
/* *** Test list penuh *** */
boolean isStringFull(ListDinString l) {
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return (NEFF_String(l) == CAPACITY_LISTDINAMIS_String(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void printListString(ListDinString l) {
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListStringEqual(ListDinString l1, ListDinString l2) {
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
    int i = 0;
    boolean cek = true;
    if (listStringLengthDinamis(l1) == listStringLengthDinamis(l2)){
        while (cek == true && i < listStringLengthDinamis(l1)){
            if (ELMT_LISTDINAMIS_String(l1,i) != ELMT_LISTDINAMIS_String(l2,i)){
                cek = false;
            }
            i += 1;
        }
    }
    return cek;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOfS(ListDinString l, ElTypeString val) {
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
    int i = 0;
    boolean cek = true;
    while (cek == true && i < listStringLengthDinamis(l)) {
        if (ELMT_LISTDINAMIS_String(l,i) == val) {
            cek = false;
        }
        i += 1;
    }
    if (cek == true) {
        return IDX_UNDEF;
    } else {
        return i;
    }
}

/* ********** OPERASI LAIN ********** */
void copyListString(ListDinString lIn, ListDinString *lOut) {
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
    int i;
    CreateListStringDin(lOut, CAPACITY_LISTDINAMIS_String(lIn));
    NEFF_String(*lOut) = NEFF_String(lIn);
    for (i = 0; i < listStringLengthDinamis(lIn); i++){
        ELMT_LISTDINAMIS_String(*lOut,i) = ELMT_LISTDINAMIS_String(lIn,i);
    }
}

int countValString(ListDinString l, ElTypeString val) {
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
    int jml = 0;
    int i, n;
    n = listStringLengthDinamis(l);
    for (i = 0; i < n; i++){
        if (ELMT_LISTDINAMIS_String(l,i) == val) {
            jml += 1;
        }
    }
    return jml;
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastString(ListDinString *l, ElTypeString val) {
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    ELMT_LISTDINAMIS_String(*l, NEFF_String(*l)) = val;
    NEFF_String(*l) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastString(ListDinString *l, ElTypeString *val) {
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = ELMT_LISTDINAMIS_String(*l,listStringLengthDinamis(*l)-1);
    NEFF_String(*l) -= 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListString(ListDinString *l, int num) {
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    CAPACITY_LISTDINAMIS_String(*l) += num;
    BUFFER_String(*l) = realloc (BUFFER_String(*l), CAPACITY_LISTDINAMIS_String(*l) * sizeof(ElTypeString));
}

void shrinkListString(ListDinString *l, int num) {
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    CAPACITY_LISTDINAMIS_String(*l) -= num;
    BUFFER_String(*l) = realloc (BUFFER_String(*l), CAPACITY_LISTDINAMIS_String(*l) * sizeof(ElTypeString));
}

void compressListString(ListDinString *l) {
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
    CAPACITY_LISTDINAMIS_String(*l) = NEFF_String(*l);
    BUFFER_String(*l) = realloc (BUFFER_String(*l), CAPACITY_LISTDINAMIS_String(*l) * sizeof(ElTypeString));
}