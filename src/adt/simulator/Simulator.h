/* File : ADTSimulator.h */
/* Definisi Simulator */

#ifndef ADTSIMULATOR_H
#define ADTSIMULATOR_H

#include "../queue/Prioqueue.h"
#include "../../include/boolean.h"
#include "../point/point.h"
#include "../matrix/matrix.h"

typedef struct {
    char username[20]; //username maksimal 20 digit
    POINT lokasi;
    PrioQueue inventory;
} Simulator;

#define Username(x)     (x).username
#define Lokasi(x)       (x).lokasi
#define Inventory(x)    (x).inventory

/* PRIMITIF SIMULATOR*/
void gantiUser(Simulator* s);
/* Mengganti username */

void gerakUser(Simulator* s, char x);
/* Menggerakkan user */

void pindahKeKulkas(Simulator* s, int id);
/* Memindahkan makanan di inventori ke kulkas */

boolean adjacent(Simulator s, Matrix m, char x);
/* Mengecek apakah simulator bersebelahan dengan tempat tertentu */

#endif