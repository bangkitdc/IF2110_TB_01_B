// File: makanan.h
// Definisi object makanan dan fungsi yang berkaitan

#ifndef MAKANAN_H
#define MAKANAN_H

#include "../../utility/boolean.h"

/* Definisi Aksi */
// typedef enum {
//     BUY = 'T',
//     FRY = 'F',
//     CHOP = 'C',
//     BOIL = 'B',
//     MIX = 'M'
// } ActionType;

/* Definisi Makanan */
typedef struct {
    int id;             /* ID makanan */
    char *name;         /* Nama makanan */
    TIME expiry;        /* Waktu kedaluwarsa */ /* temp */
    POINT location;      /* Lokasi aksi makanan */ /* temp */
    TIME delivery;      /* Lama pengiriman makanan */ /* temp */
} Makanan;

/* Selektor */
#define ID(M) M.id
#define NAME(M) M.name
#define EXP(M) M.expiry
#define LOC(M) M.location
#define DELIVERY(M) M.delivery

/* Konstruktor */
void createMakanan(Makanan *M, int id, TIME t, POINT loc, TIME d);
/* I.S. Makanan sembarang dan input sesuai batasan */
/* F.S. Makanan terdefinisi sesuai input */

/* Predikat */
boolean isMakananExpired(Makanan M, TIME t);
/* Mengembalikan true jika EXP(M) = 0 */

boolean isMakananDelivered(Makanan M, TIME t);
/* Mengembalikan true jika DELIVERY(M) = 0 */

boolean isMakananBuyable(Makanan M);
/* Mengembalikan true jika LOC(M) = BUY */

boolean isMakananFryable(Makanan M);
/* Mengembalikan true jika LOC(M) = FRY */

boolean isMakananChopable(Makanan M);
/* Mengembalikan true jika LOC(M) = CHOP */

boolean isMakananBoilable(Makanan M);
/* Mengembalikan true jika LOC(M) = BOIL */

boolean isMakananMixable(Makanan M);
/* Mengembalikan true jika LOC(M) = MIX */

/* Operasi */

/* I/O */

#endif