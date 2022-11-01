#include "infotype.h"

void MakeinfoType (infotype * x, Makanan m) {
/* Membuat makanan m agar bisa dimasukkan kedalam prioqueue */
/* I.S. sembarang */
/* F.S. terbuat infotype x yang berisikan data makanan m */

    // KAMUS

    // ALGORITMA
    Time(*x) = TIMEToMenit(EXP(m));
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
    char temploc;
    Makanan temp;

    // ALGORITMA
    tempid = 0;
    tempnama = "dummy";
    CreateTime(&tempexp, 0, 0, 0);
    CreateTime(&tempdeli, 0, 0, 0);
    temploc = 'x';

    createMakanan(&temp, tempid, tempnama, tempexp, temploc, tempdeli);
    MakeinfoType(dummy, temp);
}
