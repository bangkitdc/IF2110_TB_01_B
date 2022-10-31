#include <stdio.h>
#include "simulator.h"

/* PRIMITIF SIMULATOR*/
void createSimulator(Simulator* s, char* Username, POINT lokasi, PrioQueue inventory) {
/* Mengassign simulator */

    // ALGORITMA
    gantiUser(s, Username);
    gantiLokasi(s, lokasi);
    setInventory(s, inventory);
}

void gantiUser(Simulator * s, char* username) {
/* Mengganti username */

    // KAMUS
    int i;

    // ALGORITMA
    Username(*s) = username;
}

void gantiLokasi(Simulator * s, POINT p) {
/* Mengganti lokasi simulator */
    
    // ALGORITMA 
    Absis(Lokasi(*s)) = Absis(p);
    Ordinat(Lokasi(*s)) = Ordinat(p);
}

void gerakUser(Simulator * s, char x) {
/* Menggerakkan user */

    // KAMUS
    POINT temp;

    // ALGORITMA
    // pakai wasd
    if (x == 'w') {
        temp = MoveN(Lokasi(*s));
        gantiLokasi(s, temp);
    } else if (x == 'a') {
        temp = MoveW(Lokasi(*s));
        gantiLokasi(s, temp);
    } else if (x == 'd') {
        temp = MoveE(Lokasi(*s));
        gantiLokasi(s, temp);
    } else if (x == 's') {
        temp = MoveS(Lokasi(*s));
        gantiLokasi(s, temp);
    }
}

State simulatorToState(Simulator s, TIME currentTime) {
/* mengkonversi simulator s ke State*/
/* digunakan saat mau menyimpan State ke stack */

    // KAMUS
    State temp;

    // ALGORITMA
    InfoWaktu(temp) = currentTime;
    InfoKoordinat(temp) = Lokasi(s);
    InfoInventory(temp) = Inventory(s);

    return temp;
}

void loadState(Simulator * s, State st, TIME * currentTime, char * currentUsername) {
/* mengkonversi State dari stack ke simulator dan menyimpannya di simulator */
/* digunakan saat undo dan redo */

    // ALGORITMA
    createSimulator(s, currentUsername, InfoKoordinat(st), InfoInventory(st));
    *currentTime = InfoWaktu(st);
}

void setInventory(Simulator * s, PrioQueue inventory) {
/* mengassign inventory di awal */

    // ALGORITMA
    Inventory(*s) = inventory;
}

void pindahKeKulkas(Simulator * s, int id) {
/* Memindahkan makanan di inventori ke kulkas */

    // KAMUS

    // ALGORITMA
    
}

boolean adjacent(Simulator s, Matrix m, char x) {
/* Mengecek apakah simulator bersebelahan dengan tempat tertentu */

    // ALGORITMA

}