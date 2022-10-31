/* File: */

#ifndef LISTSTATIK_H
#define LISTSTATIK_H

#include "../../include/boolean.h"
#include "../makanan/makanan.h"

/*  Kamus Umum */
#define CAPACITY_LISTSTATIK 1000
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define MARKSTATIK -999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct {
   Makanan contents[CAPACITY_LISTSTATIK]; /* memori tempat penyimpan elemen (container) */
} ListStatikM;

/* ********** SELEKTOR ********** */
#define ELMT_LISTSTATIK(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong untuk list makanan */
void createLSMakanan(ListStatikM *l);

/* *** Banyaknya elemen *** */
int listLengthStatik(ListStatikM l);

/* *** Menambahkan elemen terakhir *** */
void insertFood(ListStatikM *l, Makanan food);
/* Proses: Menambahkan food ke dalam list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. food adalah elemen terakhir l yang baru jika id nya tidak sama 
dengan id makanan yang sudah ada dalam list sebelumnya. Jika Id nya sama dengan makanan sebelumnya,
maka food akan menimpa makanan yang sudah didefinisikan sebelumnya. */

void printCatalog(ListStatikM l);

/* Konstruktor : create List kosong untuk list resep */

#endif