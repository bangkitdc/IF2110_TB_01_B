/* File: makanan.h */
/* Implementasi Object Makanan */

#include "../../include/boolean.h"
#include "makanan.h"

/* Konstruktor */
void createMakanan(Makanan *M, int id, char *name, TIME exp, char loc, TIME delivery, POINT size) {
    /* I.S. Makanan sembarang dan input sesuai batasan */
    /* F.S. Makanan terdefinisi sesuai input */
    
    /* ALGORITMA */
    ID(*M) = id;
    NAME(*M) = name;
    EXP(*M) = exp;
    LOC(*M) = loc;
    DELIVERY(*M) = delivery;
    SIZE(*M) = size;
}

/* Predikat */
boolean isMakananExpired(Makanan M) {
/* Mengembalikan true jika EXP(M) = 0 */

    /* ALGORITMA */
    return (
        TIMEToMenit(EXP(M)) == 0
    );
}

boolean isMakananDelivered(Makanan M) {
/* Mengembalikan true jika DELIVERY(M) = 0 */

    /* ALGORITMA */
    return (
        TIMEToMenit(DELIVERY(M)) == 0
    );
}

boolean isMakananBuyable(Makanan M) {
/* Mengembalikan true jika LOC(M) = BUY */
    
    /* ALGORITMA */
    return (LOC(M) == BUY);
}

boolean isMakananFryable(Makanan M) {
/* Mengembalikan true jika LOC(M) = FRY */

    /* ALGORITMA */
    return (LOC(M) == FRY); 
}

boolean isMakananChopable(Makanan M) {
/* Mengembalikan true jika LOC(M) = CHOP */

    /* ALGORITMA */
    return (LOC(M) == CHOP);
}

boolean isMakananBoilable(Makanan M) {
/* Mengembalikan true jika LOC(M) = BOIL */

    /* ALGORITMA */
    return (LOC(M) == BOIL); 
}

boolean isMakananMixable(Makanan M) {
/* Mengembalikan true jika LOC(M) = MIX */

    /* ALGORITMA */
    return (LOC(M) == MIX);
}