#include "infotype.h"

void MakeinfoType (infotype * x, Makanan m) {
/* Membuat makanan m agar bisa dimasukkan kedalam prioqueue */
/* I.S. sembarang */
/* F.S. terbuat infotype x yang berisikan data makanan m */

    // KAMUS

    // ALGORITMA
    Time(*x) = EXP(m);
    Info(*x) = m;
}

void makeDummyInfoType(infotype * dummy) {
/* membuat infotype dummy */
/* I.S. belum terbuat infotype */
/* F.S. infotype dummy telah terbuat */

    // KAMUS
    int tempid;
    char* tempnama;
    TIME tempexp;
    TIME tempdeli;
    TIME temppengolahan;
    char temploc;
    Makanan temp;
    POINT tempsize;

    // ALGORITMA
    tempid = 0;
    tempnama = "dummy";
    CreateTime(&tempexp, 0, 0, 0);
    CreateTime(&tempdeli, 0, 0, 0);
    temploc = 'x';
    Absis(tempsize) = 0;
    Ordinat(tempsize) = 0;
    CreateTime(&temppengolahan, 0, 0, 0);

    createMakanan(&temp, tempid, tempnama, tempexp, temploc, tempdeli, tempsize, temppengolahan);
    MakeinfoType(dummy, temp);
}
