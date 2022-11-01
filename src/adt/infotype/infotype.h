#ifndef infotype_H
#define infotype_H

#include "../makanan/makanan.h"
#include "../time/time.h"

/* Definisi elemen dan address */
typedef struct {
    long time;              /* berisi waktu dalam menit */
    Makanan info;           /* makanan */
} infotype;

#define Time(e)             (e).time
#define Info(e)             (e).info

/* KREATOR */
void MakeinfoType (infotype * x, Makanan m);
/* Membuat makanan m agar bisa dimasukkan kedalam priqueue */
/* I.S. sembarang */
/* F.S. terbuat infotype x yang berisikan data makanan m */

void makeDummyInfoType(infotype * dummy);
/* membuat infotype dummy */
/* I.S. belum terbuat infotype */
/* F.S. infotype dummy telah terbuat */

#endif