/* File: */

#ifndef LISTSTATIK_H
#define LISTSTATIK_H

#include "boolean.h"
#include "makanan.h"

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
void insertLast(ListStatik *l, Makanan val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* Konstruktor : create List kosong untuk list resep */

#endif