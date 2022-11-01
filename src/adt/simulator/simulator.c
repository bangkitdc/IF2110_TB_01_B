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

boolean cekSpotKosongKulkas(MatrixKulkas kulkas, int idxX, int idxY) {
/* mengecek apakah di kulkas pada index i, j kosong */

    // KAMUS
    infotype temp;
    infotype var; // ceritanya ini dummy

    // ALGORITMA
    temp = ELMTK(kulkas, idxX, idxY);
    makeDummyInfoType(&var);

    if ((ID(Info(temp)) == ID(Info(var))) && (NAME(Info(temp)) == NAME(Info(var))) && (LOC(Info(temp)) == LOC(Info(var))) && (TIMEToMenit(EXP(Info(temp))) == TIMEToMenit(EXP(Info(var)))) && (TIMEToMenit(DELIVERY(Info(temp))) == TIMEToMenit(DELIVERY(Info(var))))) {
        return true;
    } else {
        return false;
    }
}

void pindahKeKulkas(Simulator * s, int idx, MatrixKulkas * kulkas) {
/* Memindahkan makanan di inventori dengan index idx ke kulkas */

    // KAMUS
    infotype temp;
    int i, j;
    boolean moved;

    // ALGORITMA
    DeleteAt(&Inventory(*s), idx, &temp);

    moved = false;
    for (i = 0; i <= getLastIdxRowKulkas(*kulkas); i++) {
        for (j = 0; j <= getLastIdxColKulkas(*kulkas); j++) {
            if (cekSpotKosongKulkas(*kulkas, i, j)) {
                moved = true;
                break;
            }
        }

        if (moved) {
            break;
        }
    }

    if (!moved) {
        Enqueue(&Inventory(*s), temp);
        printf("kulkas sudah penuh :(\n");
    } else {
        ELMTK(*kulkas, i, j) = temp;
    }
}

void ambilDariKulkas(Simulator * s, MatrixKulkas * kulkas, int idxX, int idxY) {
/* Mengambil makanan dari kulkas dan memasukkannya ke inventory */

    // KAMUS
    infotype dummy, temp;

    // ALGORITMA
    makeDummyInfoType(&dummy);
    if (cekSpotKosongKulkas(*kulkas, idxX, idxY)) {
        printf("Tidak ada makanan di slot itu.. :(\n");
    } else {
        temp = ELMTK(*kulkas, idxX, idxY);
        ELMTK(*kulkas, idxX, idxY) = dummy;
        Enqueue(&Inventory(*s), temp);
    }

}

boolean adjacent(Simulator s, Matrix m, char x) {
/* Mengecek apakah simulator bersebelahan dengan tempat tertentu */

    // ALGORITMA

}