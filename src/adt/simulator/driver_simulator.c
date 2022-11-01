#include <stdio.h>
#include "simulator.c"
#include "../makanan/makanan.c"

int main () {
    /*
    Simulator s;
    State st;
    char* username;
    POINT posisi;
    PrioQueue Q, Q2;
    infotype temp, tempdel;
    Makanan tempmakanan;
    TIME temptime;
    

    scanf("%20s", username);
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
    st = simulatorToState(s, temptime);
    loadState(&s, st, &temptime, username);

    if (IsEmptyPrioqueue(Inventory(s))) {
        printf("kosong bwang\n");
    } else {
        printf("ada isinya bwang\n");
    }

    printf("username : %s\n", Username(s));
    printf("lokasi : ");
    WritePoint(Lokasi(s));
    printf("\n\n");
    */
    
    MatrixKulkas kulkas;
    createMatrixKulkas(2, 2, &kulkas);
    displayMatrixKulkas(kulkas);

    Simulator s;
    State st;
    char username[20];
    POINT posisi;
    PrioQueue Q;
    infotype temp, tempdel;
    Makanan tempmakanan;
    TIME temptime;

    // siapkan simulator
    CreatePoint(&posisi, 1, 1);
    CreateEmptyPrioqueue(&Q, 10);
    scanf("%20s", username);
    createSimulator(&s, username, posisi, Q);
    CreateTime(&temptime, 0, 0, 2);
    createMakanan(&tempmakanan, 12, "ayam", temptime, 'R', temptime);
    MakeinfoType(&temp, tempmakanan);
    Enqueue(&Inventory(s), temp);
    Enqueue(&Inventory(s), temp);
    Enqueue(&Inventory(s), temp);
    Enqueue(&Inventory(s), temp);
    Enqueue(&Inventory(s), temp);
    Enqueue(&Inventory(s), temp);
    PrintPrioQueue(Inventory(s));

    printf("pindahin sekali ygy\n");
    pindahKeKulkas(&s, 0, &kulkas);
    displayMatrixKulkas(kulkas);
    PrintPrioQueue(Inventory(s));
    printf("\n");

    printf("pindahin sekali ygy\n");
    pindahKeKulkas(&s, 0, &kulkas);
    displayMatrixKulkas(kulkas);
    PrintPrioQueue(Inventory(s));
    printf("\n");

    printf("pindahin sekali ygy\n");
    pindahKeKulkas(&s, 0, &kulkas);
    displayMatrixKulkas(kulkas);
    PrintPrioQueue(Inventory(s));
    printf("\n");

    printf("pindahin sekali ygy\n");
    pindahKeKulkas(&s, 0, &kulkas);
    displayMatrixKulkas(kulkas);
    PrintPrioQueue(Inventory(s));
    printf("\n");

    printf("pindahin sekali ygy, kali ini harusnya kulkasnya sudah penuh\n");
    pindahKeKulkas(&s, 0, &kulkas);
    displayMatrixKulkas(kulkas);
    PrintPrioQueue(Inventory(s));
    printf("\n");

    printf("ini kalo misal kita pengen ngambil dari kulkas di 1,1\n");
    ambilDariKulkas(&s, &kulkas, 0, 0);
    displayMatrixKulkas(kulkas);
    PrintPrioQueue(Inventory(s));
    printf("\n");



    return 0;
}
