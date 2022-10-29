/* File : ADTSimulator.h */
/* Definisi Simulator */

#ifndef ADTSIMULATOR_H
#define ADTSIMULATOR_H

#include <stdlib.h>
#include "../queue/Prioqueue.h"
#include "../stack/stack.h"
#include "../time/time.h"
#include "../../utility/boolean.h"
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
void dealocateSimulator(Simulator *s);
/* mendealokasi simulator */

void createSimulator(Simulator* s, char* Username, POINT lokasi, PrioQueue inventory);
/* Mengassign simulator */

void inputUser(char* username);
/* menginput username */

void gantiUser(Simulator * s, char* username);
/* Mengganti username */

void gantiLokasi(Simulator * s, POINT p);
/* Mengganti lokasi simulator */

void gerakUser(Simulator* s, char x);
/* Menggerakkan user */

state simulatorToState(Simulator * s, TIME currentTime);
/* mengkonversi simulator s ke state*/
/* digunakan saat mau menyimpan state ke stack */

void loadState(Simulator * s, state st, TIME * currentTime, char * currentUsername);
/* mengkonversi state dari stack ke simulator dan menyimpannya di simulator */
/* digunakan saat undo dan redo */

void setInventory(Simulator * s, PrioQueue inventory);
/* mengassign inventory di awal */

void pindahKeKulkas(Simulator* s, int id);
/* Memindahkan makanan di inventori ke kulkas */

boolean adjacent(Simulator s, Matrix m, char x);
/* Mengecek apakah simulator bersebelahan dengan tempat tertentu */

#endif