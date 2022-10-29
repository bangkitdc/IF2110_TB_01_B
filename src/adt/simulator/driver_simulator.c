#include <stdio.h>
#include "simulator.c"
#include "../makanan/makanan.c"

/*
int main () {
    Simulator s;
    state st;
    char* username;
    POINT posisi;
    PrioQueue Q, Q2;
    infotype temp, tempdel;
    Makanan tempmakanan;
    TIME temptime;

    scanf("%s", username);
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

    printf("%s\n", Username(s));

    WritePoint(Lokasi(s));

    printf("\n");

    // ceritanya buat ngeload redo sama undo
    st = simulatorToState(s, temptime);
    loadState(&s, st, &temptime, username);

    if (IsEmptyPrioqueue(Inventory(s))) {
        printf("kosong bwang\n");
    } else {
        printf("ada isinya bwang\n");
    }

    printf("%s\n", Username(s));

    WritePoint(Lokasi(s));

    return 0;
}

*/