/* File: makanan.h */
/* Implementasi Object Makanan */

#include "../../utility/boolean.h"
#include "makanan.h"

/* Selektor */
#define ID(M) M.id
#define NAME(M) M.name
#define EXP(M) M.expiry
#define LOC(M) M.location
#define DELIVERY(M) M.delivery

/* Konstruktor */
void createMakanan(Makanan *M, int id, char *name, TIME exp, POINT loc, TIME delivery) {
    /* I.S. Makanan sembarang dan input sesuai batasan */
    /* F.S. Makanan terdefinisi sesuai input */
    
    /* ALGORITMA */
    ID(*M) = id;
    NAME(*M) = name;
    EXP(*M) = exp;
    LOC(*M) = loc;
    DELIVERY(*M) = delivery;
}

/* Predikat */
boolean isMakananExpired(Makanan M, TIME t) {
/* Mengembalikan true jika EXP(M) = 0 */

    /* ALGORITMA */
    return (
        DAY(EXP(M) == 0) &&
        HOUR(EXP(M) == 0) &&
        MINUTE(EXP(M) == 0)
    );
}

boolean isMakananDelivered(Makanan M, TIME t) {
/* Mengembalikan true jika DELIVERY(M) = 0 */

    /* ALGORITMA */
    return (
        DAY(DELIVERY(M) == 0) &&
        HOUR(DELIVERY(M) == 0) &&
        MINUTE(DELIVERY(M) == 0)
    );
}

boolean isMakananBuyable(Makanan M) {
/* Mengembalikan true jika LOC(M) = BUY */
    
    /* ALGORITMA */

}

boolean isMakananFryable(Makanan M) {
/* Mengembalikan true jika LOC(M) = FRY */

    /* ALGORITMA */

}

boolean isMakananChopable(Makanan M) {
/* Mengembalikan true jika LOC(M) = CHOP */

    /* ALGORITMA */
}

boolean isMakananBoilable(Makanan M) {
/* Mengembalikan true jika LOC(M) = BOIL */

    /* ALGORITMA */

}

boolean isMakananMixable(Makanan M) {
/* Mengembalikan true jika LOC(M) = MIX */

    /* ALGORITMA */

}