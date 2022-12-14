// File: makanan.h
// Definisi object makanan dan fungsi yang berkaitan

#ifndef MAKANAN_H
#define MAKANAN_H

#include "../../include/boolean.h"
#include "../time/time.h"
#include "../point/point.h"

/* Definisi Aksi */
typedef enum {
    BUY = 'T',
    FRY = 'F',
    CHOP = 'C',
    BOIL = 'B',
    MIX = 'M'
} ActionType;

/* Definisi Makanan */
typedef struct {
    int id;             /* ID makanan */
    char *name;         /* Nama makanan */
    TIME expiry;        /* Waktu kedaluwarsa */
    TIME delivery;      /* Lama pengiriman makanan */
    char location;      /* Lokasi aksi makanan */
    POINT size;         /* Size makanan (mxn) */
    TIME pengolahan;    /* Waktu pengolahan makanan*/
} Makanan;

/* Selektor */
#define ID(M) (M).id
#define NAME(M) (M).name
#define EXP(M) (M).expiry
#define DELIVERY(M) (M).delivery
#define LOC(M) (M).location
#define SIZE(M) (M).size
#define PENGOLAHAN(M) (M).pengolahan

/* Konstruktor */
void createMakanan(Makanan *M, int id, char *name, TIME exp, char loc, TIME delivery, POINT size, TIME pengolahan);
/* I.S. Makanan sembarang dan input sesuai batasan */
/* F.S. Makanan terdefinisi sesuai input */

/* Predikat */
boolean isMakananExpired(Makanan M);
/* Mengembalikan true jika EXP(M) = 0 */

boolean isMakananDelivered(Makanan M);
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

#endif