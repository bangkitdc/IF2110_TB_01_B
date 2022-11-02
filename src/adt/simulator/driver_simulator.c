#include <stdio.h>
#include "simulator.h"

int main () {
    Simulator s;
    State st;
    char *username;
    POINT posisi;
    PrioQueue Q, Q2;
    infotype temp, tempdel;
    Makanan tempmakanan;
    TIME temptime;
    ListDinMakanan notif;
    MatrixKulkas kulkas;
    
    CreateListMakananDin(&notif, 20);
    username = "username123";
    CreatePoint(&posisi, 1, 1);
    CreateEmptyPrioqueue(&Q, 10);
    CreateEmptyPrioqueue(&Q2, 10);

    createSimulator(&s, username, posisi, Q);
    
    // kalau di enqueue
    CreateTime(&temptime, 0, 0, 2);
    createMakanan(&tempmakanan, 12, "ayam", temptime, 'R', temptime);
    MakeinfoType(&temp, tempmakanan);

    Enqueue(&Inventory(s), temp);
    if (IsEmptyPrioqueue(Inventory(s))) {
        printf("kosong bwang\n");
    } else {
        printf("ada isinya bwang\n");
    }

    printf("username : %s\n", Username(s));
    printf("lokasi : ");
    WritePoint(Lokasi(s));

    printf("\n\n");

    printf("ceritanya ini buat ngeload state\n");
    st = simulatorToState(s, temptime, notif, kulkas);
    loadState(&s, st, &temptime, username, &notif, &kulkas);

    if (IsEmptyPrioqueue(Inventory(s))) {
        printf("kosong bwang\n");
    } else {
        printf("ada isinya bwang\n");
    }

    printf("username : %s\n", Username(s));
    printf("lokasi : ");
    WritePoint(Lokasi(s));
    printf("\n\n");


    return 0;
}