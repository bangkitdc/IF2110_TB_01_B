#include <stdio.h>
#include "simulator.h"
/*
int main () {
    Simulator s, s1;
    char username[20] = "username123";
    POINT point;
    PrioQueue Inventory;
    State st;
    TIME currentTime;
    ListDinMakanan currentNotif;
    MatrixKulkas kulkas;

    CreatePoint(&point, 1, 1);
    CreateTime(&currentTime, 0, 0, 1);
    CreateListMakananDin(&currentNotif, 10);
    createMatrixKulkas(10, 10, &kulkas);
    CreateEmptyPrioqueue(&Inventory, 10);
    createSimulator(&s, username, point, Inventory);
    

    printf("Data simulator:\n");
    printf("Username : %s\n", Username(s));
    printf("Lokasi: ");
    WritePoint(Lokasi(s));
    printf("\n");
    PrintPrioQueue(Inventory(s));
    printf("\n");
    printf("\n");

    simulatorToState(s, currentTime, currentNotif, kulkas, &st);
    printf("Data dari state:\n");
    printf("Lokasi : ");
    WritePoint(InfoKoordinat(st));
    printf("\n");
    PrintPrioQueue(InfoInventory(st));
    printf("\n");
    
    printf("Load data dari state:\n");
    loadState(&s1, &st, username, &currentNotif, &kulkas, &currentTime);

    printf("Username : %s\n", Username(s1));
    printf("Lokasi: ");
    WritePoint(Lokasi(s1));
    printf("\n");
    PrintPrioQueue(Inventory(s1));
    printf("\n");


    return 0;
}
*/