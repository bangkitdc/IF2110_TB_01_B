// #include <stdio.h>
// #include "simulator.c"

// int main () {
//     Simulator s, s1;
//     char username[20] = "username123";
//     POINT point;
//     PrioQueue Inventory;
//     State st;
//     TIME currentTime;
//     ListDinMakanan currentNotif;
//     MatrixKulkas kulkas;
//     Stack undo_stack, redo_stack;

//     CreatePoint(&point, 1, 1);
//     CreateTime(&currentTime, 0, 1, 1);
//     CreateListMakananDin(&currentNotif, 10);
//     createMatrixKulkas(10, 10, &kulkas);
//     CreateEmptyPrioqueue(&Inventory, 10);
//     createSimulator(&s, username, point, Inventory);
    

//     printf("Data simulator:\n");
//     printf("Username : %s\n", Username(s));
//     printf("Lokasi: ");
//     WritePoint(Lokasi(s));
//     printf("\n");
//     PrintPrioQueue(Inventory(s));
//     printf("\n");
//     printf("\n");

//     simulatorToState(s, currentTime, currentNotif, kulkas, &st);
//     printf("Data dari state:\n");
//     printf("Lokasi : ");
//     CreatePoint(&point, 1, 2);
//     InfoKoordinat(st) = point;
//     InfoWaktu(st) = NextMenit(InfoWaktu(st));
//     WritePoint(InfoKoordinat(st));
//     printf("\n");
//     PrintPrioQueue(InfoInventory(st));
//     printf("\n");
//     Push(&undo_stack, st);
    
//     printf("Load data dari state:\n");
//     Undo(&undo_stack, &redo_stack, &st);
//     loadState(&s1, &st, username, &currentNotif, &kulkas, &currentTime);
//     printf("Username : %s\n", Username(s1));
//     printf("Lokasi: ");
//     WritePoint(Lokasi(s1));
//     printf("\n");
//     PrintPrioQueue(Inventory(s1));
//     printf("\n");
//     TulisTIME2(currentTime);
//     printf("\n");
//     printf("\n");

//     printf("Load data dari state versi 2:\n");
//     Redo(&undo_stack, &redo_stack, &st);
//     loadState(&s1, &st, username, &currentNotif, &kulkas, &currentTime);

//     printf("Username : %s\n", Username(s1));
//     printf("Lokasi: ");
//     WritePoint(Lokasi(s1));
//     printf("\n");
//     PrintPrioQueue(Inventory(s1));
//     printf("\n");
//     TulisTIME2(currentTime);


//     return 0;
// }
