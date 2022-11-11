/* File: */

#ifndef SET_H
#define SET_H

#include "../../include/boolean.h"
#include "../makanan/makanan.h"
#include "../listdin/listdinmakanan.h"
#include "../liststatik/liststatikM.h"

/*  Kamus Umum */
#define CAPACITY_SET 50
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define MARKSET -999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct {
   int contents[CAPACITY_SET]; /* memori tempat penyimpan elemen (container) */
} Set;

/* ********** SELEKTOR ********** */
#define ELMT_SET(s, i) (s).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong untuk set */
void createSet(Set *s);

/* *** Banyaknya elemen *** */
int LengthSet(Set s);

/* isAnggota: Memeriksa apakah a merupakan anggota set s */
boolean isAnggota(int a, Set s);

/* isSubset: Memeriksa apakah set s merupakan subset dari set t */
boolean isSubset(Set s, Set t);

void makeSetFromInventory(Set *s, ListDinMakanan inventory);
/* I.S. s terdefinisi */
/* F.S. Meng-assign elemen makanan di set s dengan 1 jika
makanan terdapat di inventory dan 0 jika tidak ada */

#endif