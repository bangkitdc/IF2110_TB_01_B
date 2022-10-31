/* File : ADTSimulator.h */
/* Definisi Simulator */

#ifndef ADTSIMULATOR_H
#define ADTSIMULATOR_H

#include <stdlib.h>
#include "../queue/prioqueue.h"
#include "../stack/stack.h"
#include "../time/time.h"
#include "../../include/boolean.h"
#include "../point/point.h"
#include "../matrix/matrix.h"

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

State simulatorToState(Simulator s, TIME currentTime);
/* mengkonversi simulator s ke State*/
/* digunakan saat mau menyimpan State ke stack */

void loadState(Simulator * s, State st, TIME * currentTime, char * currentUsername);
/* mengkonversi State dari stack ke simulator dan menyimpannya di simulator */
/* digunakan saat undo dan redo */

void setInventory(Simulator * s, PrioQueue inventory);
/* mengassign inventory di awal */

void pindahKeKulkas(Simulator* s, int id);
/* Memindahkan makanan di inventori ke kulkas */

boolean adjacent(Simulator s, Matrix m, char x);
/* Mengecek apakah simulator bersebelahan dengan tempat tertentu */

#endif