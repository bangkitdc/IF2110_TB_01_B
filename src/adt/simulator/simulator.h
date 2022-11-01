/* File : ADTSimulator.h */
/* Definisi Simulator */

#ifndef ADTSIMULATOR_H
#define ADTSIMULATOR_H

#include <stdlib.h>
#include "../queue/prioqueue.c"
#include "../stack/stack.c"
#include "../time/time.c"
#include "../../include/boolean.h"
#include "../point/point.c"
#include "../matrix/matrix.c"
#include "../matrix/matrixKulkas.c"
#include "../listdin/listdinmakanan.c"

typedef struct {
    char* username;
    POINT lokasi;
    PrioQueue inventory;
} Simulator;

#define Username(x)     (x).username
#define Lokasi(x)       (x).lokasi
#define Inventory(x)    (x).inventory

/* PRIMITIF SIMULATOR*/
void createSimulator(Simulator* s, char* Username, POINT lokasi, PrioQueue inventory);
/* Mengassign simulator */

void gantiUser(Simulator * s, char* username);
/* Mengganti username */

void gantiLokasi(Simulator * s, POINT p);
/* Mengganti lokasi simulator */

void gerakUser(Simulator* s, char x);
/* Menggerakkan user */

State simulatorToState(Simulator s, TIME currentTime, ListDinMakanan currentNotif, MatrixKulkas currentKulkas);
/* mengkonversi simulator s ke State*/
/* digunakan saat mau menyimpan State ke stack */

void loadState(Simulator * s, State st, TIME * currentTime, char * currentUsername, ListDinMakanan currentNotif, MatrixKulkas currentKulkas);
/* mengkonversi State dari stack ke simulator dan menyimpannya di simulator */
/* digunakan saat undo dan redo */

void setInventory(Simulator * s, PrioQueue inventory);
/* mengassign inventory di awal */

boolean cekSpotKosongKulkas(MatrixKulkas kulkas, int idxX, int idxY);
/* mengecek apakah di kulkas pada index i, j kosong */

void pindahKeKulkas(Simulator * s, int idx, MatrixKulkas * kulkas);
/* Memindahkan makanan di inventori dengan index idx ke kulkas */

void ambilDariKulkas(Simulator * s, MatrixKulkas * kulkas, int idxX, int idxY);
/* Mengambil makanan dari kulkas dan memasukkannya ke inventory */

boolean adjacent(Simulator s, Matrix m, char x);
/* Mengecek apakah simulator bersebelahan dengan tempat tertentu */

#endif