#include "../queue/Prioqueue.h"
#include "simulator.h"
#include <stdio.h>


/* PRIMITIF SIMULATOR*/
void gantiUser(Simulator * s) {
/* Mengganti username */

    // KAMUS
    char nama[20];

    // ALGORITMA
    scanf("%s\n", nama);
    for (int i = 0; i <= 19 && nama[i] != '\0'; i++) {
        Username(*s)[i] = nama[i];
    }
}

void gerakUser(Simulator * s, char x) {
/* Menggerakkan user */

    // ALGORITMA
    // pakai wasd
    if (x == 'w') {
        Lokasi(*s) = MoveN(Lokasi(*s));
    } else if (x == 'a') {
        Lokasi(*s) = MoveW(Lokasi(*s));
    } else if (x == 'd') {
        Lokasi(*s) = MoveE(Lokasi(*s));
    } else if (x == 's') {
        Lokasi(*s) = MoveS(Lokasi(*s));
    }
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