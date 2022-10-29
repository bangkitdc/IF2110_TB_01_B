/* File: */

#ifndef LISTSTATIK_H
#define LISTSTATIK_H

#include "../../include/boolean.h"
#include "../makanan/makanan.h"

/*  Kamus Umum */
#define CAPACITY 1000
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define MARK -9999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Makanan ElType;  /* type elemen List */
typedef int IdxType;
typedef struct {
   Makanan contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListStatik;

/* ********** SELEKTOR ********** */
#define ELMT(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong untuk list makanan */
void createLSMakanan(ListStatik *l);

/* *** Banyaknya elemen *** */
int listLength(ListStatik l);

/* *** Menambahkan elemen terakhir *** */
void insertFood(ListStatik *l, Makanan food);
/* Proses: Menambahkan food ke dalam list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. food adalah elemen terakhir l yang baru jika id nya tidak sama 
dengan id makanan yang sudah ada dalam list sebelumnya. Jika Id nya sama dengan makanan sebelumnya,
maka food akan menimpa makanan yang sudah didefinisikan sebelumnya. */

/* Konstruktor : create List kosong untuk list resep */

#endif