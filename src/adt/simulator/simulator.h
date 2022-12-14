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
#include "../machine/charmachine.h"
#include "../machine/wordmachine.h"

typedef struct {
    Word username;
    POINT lokasi;
    PrioQueue inventory;
} Simulator;

#define Username(x)     (x).username
#define Lokasi(x)       (x).lokasi
#define Inventory(x)    (x).inventory

/* PRIMITIF SIMULATOR*/
void createSimulator(Simulator* s, Word Username, POINT lokasi, PrioQueue inventory);
/* Mengassign simulator */

void gantiUser(Simulator * s, Word username);
/* Mengganti username */

void gantiLokasi(Simulator * s, POINT p);
/* Mengganti lokasi simulator */

void gerakUser(Simulator * s, Map * peta, boolean * stuck, char x);
/* Menggerakkan user */

void simulatorToState(Simulator s, PrioQueue deliverylist, TIME currentTime, ListDinMakanan currentNotif, MatrixKulkas currentKulkas, State* temp);
/* mengkonversi simulator s ke State*/
/* digunakan saat mau menyimpan State ke stack */

void loadState(Simulator * s, PrioQueue * deliverylist, State st, Word currentUsername, ListDinMakanan * currentNotif, MatrixKulkas * currentKulkas, TIME * currentTime);
/* mengkonversi State dari stack ke simulator dan menyimpannya di simulator */
/* digunakan saat undo dan redo */

void copySimulator(Simulator * s1, Simulator * s2);
/* mengcopy simulator 1 ke simulator 2 */

void setInventory(Simulator * s, PrioQueue inventory);
/* mengassign inventory di awal */

/* Move Simulator */
void MNorth(Map *MGame, boolean *stuck, Simulator *s);

void MEast(Map *MGame, boolean *stuck, Simulator *s);

void MSouth(Map *MGame, boolean *stuck, Simulator *s);

void MWest(Map *MGame, boolean *stuck, Simulator *s);

boolean cekSpotKosongKulkas(MatrixKulkas kulkas, int idxX, int idxY);
/* mengecek apakah di kulkas pada index i, j kosong */

void penomorMakananKulkas(infotype * var, int id, MatrixKulkas kulkas, boolean * ada);
/* menomori makanan yang akan dimasukkan ke kulkas, dengan cara mengubah indexnya */

void hapusIdKulkas(infotype * var);
/* mengembalikan ID makanan yang sementara diubah untuk masuk ke kulkas */

void ambilDariInventory (Simulator * s, int idx, infotype * var);
/* prekondisi : idx valid */

void pindahKeKulkas(infotype var, MatrixKulkas * kulkas, ListDinMakanan * currentNotif, int idX, int idY);
/* Memindahkan makanan di inventori dengan index idx ke kulkas */

void ambilDariKulkas(Simulator * s, int idmakanan, MatrixKulkas * kulkas, ListDinMakanan * currentNotif);
/* Mengambil makanan dari kulkas dan memasukkannya ke inventory */

boolean adjacent(Simulator s, Matrix peta, char x);
/* Mengecek apakah simulator bersebelahan dengan tempat tertentu */

void displayListMakananAksi(ListStatikM listMakanan, ListStatikM *hasil, int *length, char aksi);
// menampilkan makanan apa saja yang bisa dimasak berdasarkan aksi

Tree getTreeFromMakanan(Makanan makanan, ListStatikT listResep);
// mendapatkan tree makanan dari adt makanan

Makanan getMakananFromId(int id, ListStatikM listMakanan);
// mendapatkan makanan dari id

#endif