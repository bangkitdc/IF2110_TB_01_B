// #include <stdio.h>
// #include <stdlib.h>
// #include "simulator.h"

// int main () {
//     Simulator s, s1;
//     POINT point;
//     PrioQueue Inventory;
//     PrioQueue delilist;
//     State st;
//     TIME currentTime;
//     ListDinMakanan currentNotif;
//     MatrixKulkas kulkas;
//     Stack undo_stack, redo_stack;

//     infotype temp, temp2, tempdel;
//     Makanan tempmakanan, tempmakanan2;
//     TIME temptime, temptime2;
//     ListDinMakanan notif;
//     POINT templokasi;

//     CreatePoint(&templokasi, 1, 1);
//     CreateTime(&temptime, 1, 3, 2);
//     createMakanan(&tempmakanan, 12, "ayam", temptime, 'R', temptime, templokasi, temptime);
//     MakeinfoType(&temp, tempmakanan);
//     CreateTime(&temptime2, 0, 2, 3);
//     createMakanan(&tempmakanan2, 13, "bebek", temptime2, 'R', temptime2, templokasi, temptime2);
//     MakeinfoType(&temp2, tempmakanan2);
//     CreatePoint(&point, 1, 1);
//     CreateTime(&currentTime, 0, 1, 1);
//     CreateListMakananDin(&currentNotif, 10);
//     createMatrixKulkas(10, 10, &kulkas);
//     CreateEmptyStack(&undo_stack);
//     CreateEmptyStack(&redo_stack);
//     CreateEmptyPrioqueue(&Inventory, 10);
//     CreateEmptyPrioqueue(&delilist, 10);
//     createSimulator(&s, "ADMIN", point, Inventory);
//     simulatorToState(s, delilist, currentTime, currentNotif, kulkas, &st);
//     Enqueue(&Inventory(s), temp);
//     Enqueue(&Inventory(s), temp);
//     Enqueue(&Inventory(s), temp);
//     Enqueue(&Inventory(s), temp2);
//     Enqueue(&Inventory(s), temp2);
//     Enqueue(&Inventory(s), temp2);
//     simulatorToState(s, delilist, currentTime, currentNotif, kulkas, &st);
//     PrintPrioQueue(Inventory(st));
//     Push(&undo_stack, st);
//     // coba passtime
//     PasstimeQueue(&Inventory(s), 10, &currentNotif);
//     PasstimeQueue(&Inventory(s), 10, &currentNotif);
//     simulatorToState(s, delilist, currentTime, currentNotif, kulkas, &st);
//     Push(&undo_stack, st);
//     Undo(&undo_stack, &redo_stack, &st);
//     loadState(&s, &delilist, st, "ADMIN", &currentNotif, &kulkas, &currentTime);
//     PrintPrioQueue(Inventory(s));
//     PasstimeQueue(&Inventory(s), 30, &currentNotif);
//     simulatorToState(s, delilist, currentTime, currentNotif, kulkas, &st);
//     Push(&undo_stack, st);
//     Undo(&undo_stack, &redo_stack, &st);
//     Redo(&undo_stack, &redo_stack, &st);
//     loadState(&s, &delilist, st, "ADMIN", &currentNotif, &kulkas, &currentTime);
//     PrintPrioQueue(Inventory(s));

    // simulatorToState(s, delilist, currentTime, currentNotif, kulkas, &st);
    // Push(&undo_stack, st);

    // Pop(&undo_stack, &st);
    // PrintPrioQueue(Inventory(st));

    // /* BAGIAN TESTING KULKAS */
    // Simulator s;
    // MatrixKulkas kulkas;
    // PrioQueue Inventory;
    // POINT lokasi, size, size2, size3;
    // Makanan tempmakanan, tempmakanan2, tempmakanan3;
    // TIME temptime, temptime2, temptime3, currentTime;
    // infotype temp, temp2, temp3;
    // ListDinMakanan notif;
    // boolean valid; 
    // int i, j;

    // CreateListMakananDin(&notif, 20);
    // CreateTime(&temptime, 1, 3, 2);
    // CreatePoint(&size, 2, 2);
    // CreatePoint(&size2, 1, 3);
    // createMakanan(&tempmakanan, 12, "ayam", temptime, 'R', temptime, size, temptime);
    // MakeinfoType(&temp, tempmakanan);

    // CreateTime(&temptime2, 0, 2, 3);
    // createMakanan(&tempmakanan2, 13, "bebek", temptime2, 'R', temptime2, size, temptime2);
    // MakeinfoType(&temp2, tempmakanan2);

    // CreateTime(&temptime3, 0, 2, 2);
    // createMakanan(&tempmakanan3, 14, "bebek2", temptime3, 'R', temptime3, size2, temptime3);
    // MakeinfoType(&temp3, tempmakanan3);

    // createMatrixKulkas(10, 20, &kulkas);
    // CreateEmptyPrioqueue(&Inventory, 10);
    // CreatePoint(&lokasi, 1, 1);
    // createSimulator(&s, "ADMIN", lokasi, Inventory);

    // printf("Kondisi awal\n");
    // Enqueue(&Inventory(s), temp);
    // Enqueue(&Inventory(s), temp2);
    // Enqueue(&Inventory(s), temp);
    // Enqueue(&Inventory(s), temp3);
    // Enqueue(&Inventory(s), temp3);
    // PrintPrioQueue(Inventory(s));
    // printf("\n");

    // displayMatrixKulkas(kulkas);
    // printf("\n");

    // printf("Setelah dipindahkan ke kulkas\n\n");
    // ambilDariInventory(&s, 1, &temp);
    // penomorMakananKulkas(&temp, 7, kulkas, &valid);
    // PrintPrioQueue(Inventory(s));
    // printf("\n");
    // int kiri = 0;
    // int atas = 0;
    // int kanan = 1;
    // int bawah = 1;

    // for (i = atas; i <= bawah; i++) {
    //     for (j = kiri; j <= kanan; j++) {
    //         pindahKeKulkas(temp, &kulkas, &notif, i, j);
    //     }
    // }
    // displayMatrixKulkas(kulkas);
    // printf("\n");

    // printf("Jika memasukkan makanan yang tidak square\n\n");
    // ambilDariInventory(&s, 1, &temp);
    // penomorMakananKulkas(&temp, 6, kulkas, &valid);
    // kiri = 6;
    // atas = 0;
    // kanan = 6;
    // bawah = 2;
    // for (i = atas; i <= bawah; i++) {
    //     for (j = kiri; j <= kanan; j++) {
    //         pindahKeKulkas(temp, &kulkas, &notif, i, j);
    //     }
    // }

    // ambilDariInventory(&s, 1, &temp);
    // penomorMakananKulkas(&temp, 6, kulkas, &valid);
    // kiri = 8;
    // atas = 0;
    // kanan = 10;
    // bawah = 0;
    // for (i = atas; i <= bawah; i++) {
    //     for (j = kiri; j <= kanan; j++) {
    //         pindahKeKulkas(temp, &kulkas, &notif, i, j);
    //     }
    // }
    // displayMatrixKulkas(kulkas);
    // printf("\n");

    // printf("Mengambil makanan dari kulkas\n\n");
    // ambilDariKulkas(&s, 14007, &kulkas, &notif);
    // PrintPrioQueue(Inventory(s));
    // printf("\n");
    // displayMatrixKulkas(kulkas);

//     return 0;
// }
