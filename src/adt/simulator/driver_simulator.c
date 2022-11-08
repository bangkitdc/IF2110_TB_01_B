// #include <stdio.h>
// #include "simulator.h"

// int main () {
//     // Simulator s, s1;
//     // char username[20] = "username123";
//     // POINT point;
//     // PrioQueue Inventory;
//     // State st;
//     // TIME currentTime;
//     // ListDinMakanan currentNotif;
//     // MatrixKulkas kulkas;
//     // Stack undo_stack, redo_stack;

//     // CreatePoint(&point, 1, 1);
//     // CreateTime(&currentTime, 0, 1, 1);
//     // CreateListMakananDin(&currentNotif, 10);
//     // createMatrixKulkas(10, 10, &kulkas);
//     // CreateEmptyPrioqueue(&Inventory, 10);
//     // createSimulator(&s, username, point, Inventory);
    

//     // printf("Data simulator:\n");
//     // printf("Username : %s\n", Username(s));
//     // printf("Lokasi: ");
//     // WritePoint(Lokasi(s));
//     // printf("\n");
//     // PrintPrioQueue(Inventory(s));
//     // printf("\n");
//     // printf("\n");

//     // simulatorToState(s, currentTime, currentNotif, kulkas, &st);
//     // printf("Data dari state:\n");
//     // printf("Lokasi : ");
//     // CreatePoint(&point, 1, 2);
//     // InfoKoordinat(st) = point;
//     // InfoWaktu(st) = NextMenit(InfoWaktu(st));
//     // WritePoint(InfoKoordinat(st));
//     // printf("\n");
//     // PrintPrioQueue(InfoInventory(st));
//     // printf("\n");
//     // Push(&undo_stack, st);
    
//     // printf("Load data dari state:\n");
//     // Undo(&undo_stack, &redo_stack, &st);
//     // loadState(&s1, &st, username, &currentNotif, &kulkas, &currentTime);
//     // printf("Username : %s\n", Username(s1));
//     // printf("Lokasi: ");
//     // WritePoint(Lokasi(s1));
//     // printf("\n");
//     // PrintPrioQueue(Inventory(s1));
//     // printf("\n");
//     // TulisTIME2(currentTime);
//     // printf("\n");
//     // printf("\n");

//     // printf("Load data dari state versi 2:\n");
//     // Redo(&undo_stack, &redo_stack, &st);
//     // loadState(&s1, &st, username, &currentNotif, &kulkas, &currentTime);

//     // printf("Username : %s\n", Username(s1));
//     // printf("Lokasi: ");
//     // WritePoint(Lokasi(s1));
//     // printf("\n");
//     // PrintPrioQueue(Inventory(s1));
//     // printf("\n");
//     // TulisTIME2(currentTime);

//     /* BAGIAN TESTING KULKAS */
//     Simulator s;
//     MatrixKulkas kulkas;
//     PrioQueue Inventory;
//     POINT lokasi, size, size2, size3;
//     Makanan tempmakanan, tempmakanan2, tempmakanan3;
//     TIME temptime, temptime2, temptime3, currentTime;
//     infotype temp, temp2, temp3;
//     ListDinMakanan notif;
//     boolean valid; 
//     int i, j;

//     CreateListMakananDin(&notif, 20);
//     CreateTime(&temptime, 1, 3, 2);
//     CreatePoint(&size, 2, 2);
//     CreatePoint(&size2, 1, 3);
//     createMakanan(&tempmakanan, 12, "ayam", temptime, 'R', temptime, size, temptime);
//     MakeinfoType(&temp, tempmakanan);

//     CreateTime(&temptime2, 0, 2, 3);
//     createMakanan(&tempmakanan2, 13, "bebek", temptime2, 'R', temptime2, size, temptime2);
//     MakeinfoType(&temp2, tempmakanan2);

//     CreateTime(&temptime3, 0, 2, 2);
//     createMakanan(&tempmakanan3, 14, "bebek2", temptime3, 'R', temptime3, size2, temptime3);
//     MakeinfoType(&temp3, tempmakanan3);

//     createMatrixKulkas(10, 20, &kulkas);
//     CreateEmptyPrioqueue(&Inventory, 10);
//     CreatePoint(&lokasi, 1, 1);
//     createSimulator(&s, "ADMIN", lokasi, Inventory);

//     printf("Kondisi awal\n");
//     Enqueue(&Inventory(s), temp);
//     Enqueue(&Inventory(s), temp2);
//     Enqueue(&Inventory(s), temp);
//     Enqueue(&Inventory(s), temp3);
//     Enqueue(&Inventory(s), temp3);
//     PrintPrioQueue(Inventory(s));
//     printf("\n");

//     displayMatrixKulkas(kulkas);
//     printf("\n");

//     printf("Setelah dipindahkan ke kulkas\n\n");
//     ambilDariInventory(&s, 1, &temp);
//     penomorMakananKulkas(&temp, 7, kulkas, &valid);
//     PrintPrioQueue(Inventory(s));
//     printf("\n");
//     int kiri = 0;
//     int atas = 0;
//     int kanan = 1;
//     int bawah = 1;

//     for (i = atas; i <= bawah; i++) {
//         for (j = kiri; j <= kanan; j++) {
//             pindahKeKulkas(temp, &kulkas, &notif, i, j);
//         }
//     }
//     displayMatrixKulkas(kulkas);
//     printf("\n");

//     printf("Jika memasukkan makanan yang tidak square\n\n");
//     ambilDariInventory(&s, 1, &temp);
//     penomorMakananKulkas(&temp, 6, kulkas, &valid);
//     kiri = 6;
//     atas = 0;
//     kanan = 6;
//     bawah = 2;
//     for (i = atas; i <= bawah; i++) {
//         for (j = kiri; j <= kanan; j++) {
//             pindahKeKulkas(temp, &kulkas, &notif, i, j);
//         }
//     }

//     ambilDariInventory(&s, 1, &temp);
//     penomorMakananKulkas(&temp, 6, kulkas, &valid);
//     kiri = 8;
//     atas = 0;
//     kanan = 10;
//     bawah = 0;
//     for (i = atas; i <= bawah; i++) {
//         for (j = kiri; j <= kanan; j++) {
//             pindahKeKulkas(temp, &kulkas, &notif, i, j);
//         }
//     }
//     displayMatrixKulkas(kulkas);
//     printf("\n");

//     printf("Mengambil makanan dari kulkas\n\n");
//     ambilDariKulkas(&s, 14007, &kulkas, &notif);
//     PrintPrioQueue(Inventory(s));
//     printf("\n");
//     displayMatrixKulkas(kulkas);

//     return 0;
// }
