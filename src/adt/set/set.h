/* File: */

#ifndef SET_H
#define SET_H

#include "../../include/boolean.h"
#include "../makanan/makanan.h"
#include "../listdin/listdinmakanan.h"
#include "../liststatik/liststatikM.h"
#include "../infotype/infotype.h"

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

void makeSetFromListMakanan(Set *s, ListStatikM daftarMakanan);
/* I.S. s terdefinisi */
/* F.S. Meng-assign elemen-elemen pada set s dengan 0 pada daftarMakanan */

void makeSetFromInventory(Set *s, ListStatikM daftarMakanan, ListDinMakanan inventory);
/* I.S. s terdefinisi */
/* F.S. Meng-assign elemen tertentu pada set s dengan 1 jika makanan yang berkorespondensi dengan indeks daftarMakanan
tersedia di inventory */


#endif