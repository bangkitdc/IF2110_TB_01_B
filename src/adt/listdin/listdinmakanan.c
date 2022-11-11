/* File: listdinmakanan.c */

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
    BUFFER_Makanan(*l) = malloc (capacity*sizeof(infotype));
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

/* ********** TEST KOSONG ********** */
/* *** Test list kosong *** */
boolean isEmptyListMakanan(ListDinMakanan l) {
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */

    return (NEFF_Makanan(l) == 0);
}

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
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong maka akan ditulis kelayar hasil-hasil dari list tersebut */
/* Jika list kosong : menulis - */
/* Jika tidak kosong, contoh :
    - Ayam berhasil digoreng 
    - Ayam goreng kadaluarsa
    - Ayam berhasil masuk inventory */

    // KAMUS
    int i;

    // ALGORITMA
    printf("Notifikasi: ");
    if (isEmptyListMakanan(l)) {
        printf("-\n");
    } else {
        printf("\n");
        for (i = getFirstIdxS(l); i <= getLastIdxS(l); i++) {
            if (TIMEToMenit(Time(ELMT_LISTDINAMIS_Makanan(l, i))) == 0) {
                printf("- %s telah kadaluarsa :(\n", NAME(Info(ELMT_LISTDINAMIS_Makanan(l, i))));
            } else {
                if (LOC(Info(ELMT_LISTDINAMIS_Makanan(l, i))) == 'F') {
                    printf("- %s telah digoreng\n", NAME(Info(ELMT_LISTDINAMIS_Makanan(l, i))));
                } else if (LOC(Info(ELMT_LISTDINAMIS_Makanan(l, i))) == 'T') {
                    printf("- %s telah masuk ke inventory\n", NAME(Info(ELMT_LISTDINAMIS_Makanan(l, i))));
                } else if (LOC(Info(ELMT_LISTDINAMIS_Makanan(l, i))) == 't') {
                    printf("- %s telah masuk ke delivery list\n", NAME(Info(ELMT_LISTDINAMIS_Makanan(l, i))));
                } else if (LOC(Info(ELMT_LISTDINAMIS_Makanan(l, i))) == 'C') {
                    printf("- %s telah terpotong\n", NAME(Info(ELMT_LISTDINAMIS_Makanan(l, i))));
                } else if (LOC(Info(ELMT_LISTDINAMIS_Makanan(l, i))) == 'B') {
                    printf("- %s telah direbus\n", NAME(Info(ELMT_LISTDINAMIS_Makanan(l, i))));
                } else if (LOC(Info(ELMT_LISTDINAMIS_Makanan(l, i))) == 'M') {
                    printf("- %s telah dicampur\n", NAME(Info(ELMT_LISTDINAMIS_Makanan(l, i))));
                } else if (LOC(Info(ELMT_LISTDINAMIS_Makanan(l, i))) == 'K') {
                    printf("- %s telah masuk kulkas\n", NAME(Info(ELMT_LISTDINAMIS_Makanan(l, i))));
                }
            }
        }
    }
}

void printListMakananUndo(ListDinMakanan l) {
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong maka akan ditulis kelayar hasil-hasil dari list tersebut */
/* Jika list kosong : menulis - */
/* Jika tidak kosong, contoh :
    - Ayam goreng tidak jadi digoreng
    - Ayam masuk kembali ke delivery list */

    // KAMUS
    int i;

    // ALGORITMA
    printf("Notifikasi: ");
    if (isEmptyListMakanan(l)) {
        printf("-\n");
    } else {
        printf("\n");
        for (i = getFirstIdxS(l); i <= getLastIdxS(l); i++) {
            if (TIMEToMenit(Time(ELMT_LISTDINAMIS_Makanan(l, i))) == 0) {
                printf("- %s dikembalikan ke inventory\n", NAME(Info(ELMT_LISTDINAMIS_Makanan(l, i))));
            } else {
                if (LOC(Info(ELMT_LISTDINAMIS_Makanan(l, i))) == 'F') {
                    printf("- %s tidak jadi digoreng\n", NAME(Info(ELMT_LISTDINAMIS_Makanan(l, i))));
                } else if (LOC(Info(ELMT_LISTDINAMIS_Makanan(l, i))) == 'T') {
                    printf("- %s masuk kembali ke delivery list\n", NAME(Info(ELMT_LISTDINAMIS_Makanan(l, i))));
                } else if (LOC(Info(ELMT_LISTDINAMIS_Makanan(l, i))) == 't') {
                    printf("- %s tidak jadi masuk delivery list\n", NAME(Info(ELMT_LISTDINAMIS_Makanan(l, i))));
                } else if (LOC(Info(ELMT_LISTDINAMIS_Makanan(l, i))) == 'C') {
                    printf("- %s tidak jadi dipotong\n", NAME(Info(ELMT_LISTDINAMIS_Makanan(l, i))));
                } else if (LOC(Info(ELMT_LISTDINAMIS_Makanan(l, i))) == 'B') {
                    printf("- %s tidak jadi direbus\n", NAME(Info(ELMT_LISTDINAMIS_Makanan(l, i))));
                } else if (LOC(Info(ELMT_LISTDINAMIS_Makanan(l, i))) == 'M') {
                    printf("- %s tidak jadi dicampur\n", NAME(Info(ELMT_LISTDINAMIS_Makanan(l, i))));
                } else if (LOC(Info(ELMT_LISTDINAMIS_Makanan(l, i))) == 'K') {
                    printf("- %s dikeluarkan dari kulkas\n", NAME(Info(ELMT_LISTDINAMIS_Makanan(l, i))));
                }
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastMakanan(ListDinMakanan *l, infotype val) {
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    ELMT_LISTDINAMIS_Makanan(*l, NEFF_Makanan(*l)) = val;
    NEFF_Makanan(*l) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastMakanan(ListDinMakanan *l, infotype *val) {
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
    BUFFER_Makanan(*l) = realloc (BUFFER_Makanan(*l), CAPACITY_LISTDINAMIS_Makanan(*l) * sizeof(infotype));
}

/* ********* MENYALIN ISI LISTDIN ********* */
void copyListDinMakanan(ListDinMakanan l1, ListDinMakanan *l2)
{
    /* Menyalin elemen di l1 ke l2 */

    CreateListMakananDin(l2, CAPACITY_LISTDINAMIS_Makanan(l1));
    for (int i = 0; i < NEFF_Makanan(l1); i++)
    {
        insertLastMakanan(l2, ELMT_LISTDINAMIS_Makanan(l1, i));
    }
}