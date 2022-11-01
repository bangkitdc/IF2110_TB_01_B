#include <stdio.h>
#include "prioqueue.c"
#include "../makanan/makanan.c"
/*
int main() {
    int max = 1; // walaupun max = 0, jika di enqueue nanti maxel = 2*0 + 1
    PrioQueue Q, Qcopy, currentinventory;
    infotype temp, temp2, tempdel;
    Makanan tempmakanan, tempmakanan2;
    TIME temptime, temptime2;
    ListDinMakanan notif;

    CreateEmptyPrioqueue(&Q, max);
    CreateEmptyPrioqueue(&Qcopy, max);
    CreateEmptyPrioqueue(&currentinventory, max);
    CreateListMakananDin(&notif, 100);

    CreateTime(&temptime, 0, 0, 2);
    createMakanan(&tempmakanan, 12, "ayam", temptime, 'R', temptime);
    MakeinfoType(&temp, tempmakanan);
    Enqueue(&Q, temp);
    Enqueue(&Q, temp);
    Enqueue(&Q, temp);

    CreateTime(&temptime2, 0, 0, 3);

    createMakanan(&tempmakanan2, 13, "bebek", temptime, 'R', temptime2);
    MakeinfoType(&temp2, tempmakanan2);
    Enqueue(&Q, temp2);

    // Dequeue(&Q, &temp);
    // Delete(&Q, 0, &temp);

    CopyQueue(&Q, &Qcopy);

    if (IsEmptyPrioqueue(Q)) {
        printf("kosong bang\n");
    } else {
        // idealnya prioqueue akan selalu ada isinya karena direalisasikan dengan list dinamik
        printf("ada isi bwang\n");
        PrintPrioQueue(Q);
        printf("\n");

        printf("kalo dicopy ntar begini bwang");
        PrintPrioQueue(Qcopy);
        printf("\n");

        printf("kalo yang dicopy di dequeue ntar begini bwang\n");
        Dequeue(&Qcopy, &tempdel);
        PrintPrioQueue(Qcopy);
        printf("\n");

        printf("kalo yang dicopy misal kita delete elemen dengan id 12 begini bwang\n"); // prekondisi : pasti ada di dalam prioqueue
        Delete(&Qcopy, 12, &tempdel);
        PrintPrioQueue(Qcopy);
        printf("\n");

        printf("kalo misal yang dicopy di wait 1 menit begini bang\n");
        PasstimeQueue(&Qcopy, 1, &notif); // ceritanya bakal dipake di setiap operasi, bakal mendahului segala command, dan menampilkan barang-barang yang kedaluwarsa
        PrintPrioQueue(Qcopy);
        printListMakanan(notif);
        printf("\n");

        printf("kalo misal yang dicopy di wait 1 menit lagi begini bang\n");
        PasstimeQueue(&Qcopy, 1, &notif); // ceritanya bakal dipake di setiap operasi, bakal mendahului segala command, dan menampilkan barang-barang yang kedaluwarsa
        PrintPrioQueue(Qcopy);
        printListMakanan(notif);
        printf("\n");

        printf("kalo misal notif itu mau di undo\n");
        printListMakananUndo(notif);
        printf("\n");

        
        printf("ini ceritanya kalo misal Qcopy itu delivery list sama currentinventory itu inventory di simulator\n");
        printf("ceritanya juga di skip 1 menit\n");
        PassTimeDelivery(&Qcopy, &currentinventory, 1);
        PrintPrioQueue(currentinventory);
        printf("\n");

        printf("ini ceritanya mau nyari index ayam di queue\n");
        printf("index : %d\n", IndexOfPrioqueue(currentinventory, temp));
        printf("\n");

        printf("ini ceritanya mau mengakses elemen dengan index idx di queue\n");
        infotype tes;
        printf("%d\n", ID(Info(GetElmtPrioqueue(currentinventory, 0))));
        printf("\n");

        printf("ini ceritanya mau ngehapus di index 0 bwang\n");
        infotype tes1;
        DeleteAt(&currentinventory, 1, &tes1);
        PrintPrioQueue(currentinventory);
        printf("\n");

        printf("ini ceritanya buat dummy\n");
        infotype dummy;
        makeDummyInfoType(&dummy);
        printf("keterangan dummy:\n");
        printf("ID : %d\n", ID(Info(dummy)));
        printf("nama : %s\n", NAME(Info(dummy)));
        printf("EXP : ");
        TulisTIME(EXP(Info(dummy)));
        printf("\n");
        printf("Delivery : ");
        TulisTIME(DELIVERY(Info(dummy)));
        printf("\n");
        printf("location : %c\n", LOC(Info(dummy)));

    }

    return 0;
}
*/