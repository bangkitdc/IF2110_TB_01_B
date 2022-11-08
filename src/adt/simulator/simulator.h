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
#include "../matrix/matrixKulkas.h"
#include "../liststatik/liststatikM.h"
#include "../liststatik/liststatikT.h"
#include "../listdin/listdinmakanan.h"
#include "../infotype/infotype.h"
#include "../map/map.h"
#include "../makanan/makanan.h"

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

void gerakUser(Simulator * s, Map * peta, boolean * stuck, char x);
/* Menggerakkan user */

void simulatorToState(Simulator s, TIME currentTime, ListDinMakanan currentNotif, MatrixKulkas currentKulkas, State* temp);
/* mengkonversi simulator s ke State*/
/* digunakan saat mau menyimpan State ke stack */

void loadState(Simulator * s, State * st, char * currentUsername, ListDinMakanan * currentNotif, MatrixKulkas * currentKulkas, TIME * currentTime);
/* mengkonversi State dari stack ke simulator dan menyimpannya di simulator */
/* digunakan saat undo dan redo */

void setInventory(Simulator * s, PrioQueue inventory);
/* mengassign inventory di awal */

/* Move Simulator */
void MNorth(Map *MGame, boolean *stuck, Simulator *s);

void MEast(Map *MGame, boolean *stuck, Simulator *s);

void MSouth(Map *MGame, boolean *stuck, Simulator *s);

void MWest(Map *MGame, boolean *stuck, Simulator *s);

boolean cekSpotKosongKulkas(MatrixKulkas kulkas, int idxX, int idxY);
/* mengecek apakah di kulkas pada index i, j kosong */

void pindahKeKulkas(Simulator * s, int idx, MatrixKulkas * kulkas, ListDinMakanan * currentNotif);
/* Memindahkan makanan di inventori dengan index idx ke kulkas */

void ambilDariKulkas(Simulator * s, MatrixKulkas * kulkas, int idxX, int idxY, ListDinMakanan * currentNotif);
/* Mengambil makanan dari kulkas dan memasukkannya ke inventory */

boolean adjacent(Simulator s, Map peta, char x);
/* Mengecek apakah simulator bersebelahan dengan tempat tertentu */

void displayListMakananAksi(ListStatikM listMakanan, ListStatikM *hasil, int *length, char aksi);
// menampilkan makanan apa saja yang bisa dimasak berdasarkan aksi

Tree getTreeFromMakanan(Makanan makanan, ListStatikT listResep);
// mendapatkan tree makanan dari adt makanan

void mengolahMakanan(Makanan makananOlah, PrioQueue *inventory, ListStatikT listResep, ListStatikM listMakanan);
// mengolah makanan

Makanan getMakananFromId(int id, ListStatikM listMakanan);

#endif