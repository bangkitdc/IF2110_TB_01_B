#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"

/* PRIMITIF SIMULATOR*/
void createSimulator(Simulator* s, Word Username, POINT lokasi, PrioQueue inventory) {
/* Mengassign simulator */

    // ALGORITMA
    gantiUser(s, Username);
    gantiLokasi(s, lokasi);
    setInventory(s, inventory);
}

void gantiUser(Simulator * s, Word username) {
/* Mengganti username */

    // KAMUS
    int i;

    // ALGORITMA
    copyWord(username, &Username(*s));
    // Username(*s) = username;
}

void gantiLokasi(Simulator * s, POINT p) {
/* Mengganti lokasi simulator */
    
    // ALGORITMA 
    Absis(Lokasi(*s)) = Absis(p);
    Ordinat(Lokasi(*s)) = Ordinat(p);
}

void gerakUser(Simulator * s, Map * peta, boolean * stuck, char x) {
/* Menggerakkan user */

    // KAMUS

    // ALGORITMA
    if (x == 'w') {
        MNorth(peta, stuck, s);
    } else if (x == 'a') {
        MWest(peta, stuck, s);
    } else if (x == 'd') {
        MEast(peta, stuck, s);
    } else if (x == 's') {
        MSouth(peta, stuck, s);
    }
}

void simulatorToState(Simulator s, PrioQueue deliverylist, TIME currentTime, ListDinMakanan currentNotif, MatrixKulkas currentKulkas, State* temp) {
/* mengkonversi simulator s ke State*/
/* digunakan saat mau menyimpan State ke stack */

    // ALGORITMA
    InfoWaktu(*temp) = currentTime;
    InfoKoordinat(*temp) = Lokasi(s);
    InfoInventory(*temp) = Inventory(s);
    InfoNotif(*temp) = currentNotif;
    InfoKulkas(*temp) = currentKulkas;
    InfoDelivery(*temp) = deliverylist;
}

void loadState(Simulator * s, PrioQueue * deliverylist, State st, Word currentUsername, ListDinMakanan * currentNotif, MatrixKulkas * currentKulkas, TIME * currentTime) {
/* mengkonversi State dari stack ke simulator dan menyimpannya di simulator */
/* digunakan saat undo dan redo */

    // KAMUS

    // ALGORITMA
    createSimulator(s, currentUsername, InfoKoordinat(st), InfoInventory(st));
    *currentTime = InfoWaktu(st);
    *currentNotif = InfoNotif(st);
    *currentKulkas = InfoKulkas(st);
    *deliverylist = InfoDelivery(st);
    // PrintPrioQueueDelivery(*deliverylist);
}

void copySimulator(Simulator * s1, Simulator * s2) {
/* mengcopy simulator 1 ke simulator 2 */

    // KAMUS
    PrioQueue temp;
    POINT temppoint;
    Word tempname;

    // ALGORITMA
    CreateEmptyPrioqueue(&temp, MaxElPrioqueue(Inventory(*s1)));
    CopyQueue(&Inventory(*s1), &temp);
    CreatePoint(&temppoint, Absis(Lokasi(*s1)), Ordinat(Lokasi(*s1)));
    // tempname = Username(*s1);
    copyWord(Username(*s1), &tempname);

    createSimulator(s2, tempname, temppoint, temp);
}

void setInventory(Simulator * s, PrioQueue inventory) {
/* mengassign inventory di awal */

    // ALGORITMA
    Inventory(*s) = inventory;
}

/* Move Simulator */
void MNorth(Map *MGame, boolean *stuck, Simulator *s){
    if (Absis(Lokasi(*s)) -1 >= 0 && Absis(Lokasi(*s))-1 < (*MGame).Peta.rowEff) {
        if (Ordinat(Lokasi(*s)) >= 0 && Ordinat(Lokasi(*s)) < (*MGame).Peta.colEff) {
            if ((((*MGame).Peta.mem[Absis(Lokasi(*s)) -1][Ordinat(Lokasi(*s))])) == '#' ) {
                *stuck = false;
                Absis(Lokasi(*s))--;
            } else {
                *stuck = true;
            }
        } else {
            *stuck = true;
        }
    } else {
        *stuck = true;
    }
}

void MEast(Map *MGame, boolean *stuck, Simulator *s){
    if (Absis(Lokasi(*s)) >= 0 && Absis(Lokasi(*s)) < (*MGame).Peta.rowEff) {
        if (Ordinat(Lokasi(*s))+1 >= 0 && Ordinat(Lokasi(*s))+1 < (*MGame).Peta.colEff) {
            if ((((*MGame).Peta.mem[Absis(Lokasi(*s))][Ordinat(Lokasi(*s)) +1])) == '#' ) {
                *stuck = false;
                Ordinat(Lokasi(*s))++;
            } else {
                *stuck = true;
            }
        } else {
            *stuck = true;
        }
    } else {
        *stuck = true;
    }
}

void MSouth(Map *MGame, boolean *stuck, Simulator *s){
    if (Absis(Lokasi(*s)) +1 >= 0 && Absis(Lokasi(*s))+1 < (*MGame).Peta.rowEff) {
        if (Ordinat(Lokasi(*s)) >= 0 && Ordinat(Lokasi(*s)) < (*MGame).Peta.colEff) {
            if ((((*MGame).Peta.mem[Absis(Lokasi(*s)) +1][Ordinat(Lokasi(*s))])) == '#' ) {
                *stuck = false;
                Absis(Lokasi(*s))++;
            } else {
                *stuck = true;
            }
        } else {
            *stuck = true;
        }
    } else {
        *stuck = true;
    }
}

void MWest(Map *MGame, boolean *stuck, Simulator *s){
    if (Absis(Lokasi(*s)) >= 0 && Absis(Lokasi(*s)) < (*MGame).Peta.rowEff) {
        if (Ordinat(Lokasi(*s)) -1 >= 0 && Ordinat(Lokasi(*s)) -1 < (*MGame).Peta.colEff) {
            if ((((*MGame).Peta.mem[Absis(Lokasi(*s))][Ordinat(Lokasi(*s)) -1])) == '#' ) {
                *stuck = false;
                Ordinat(Lokasi(*s))--;
            } else {
                *stuck = true;
            }
        } else {
            *stuck = true;
        }
    } else {
        *stuck = true;
    }
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

void penomorMakananKulkas(infotype * var, int id, MatrixKulkas kulkas, boolean * ada) {
/* menomori makanan yang akan dimasukkan ke kulkas, dengan cara mengubah indexnya */

    // KAMUS
    int temp, i, j;

    // ALGORITMA
    temp = ID(Info(*var));
    temp = temp * 1000 + id;

    // cek apakah ada makanan dengan id yang sama di kulkas
    *ada = false;
    for (i = 0; i <= getLastIdxRowKulkas(kulkas); i++) {
        for (j = 0; j <= getLastIdxColKulkas(kulkas); j++) {
            if (ID(Info(ELMTK(kulkas, i, j))) == temp) {
                *ada = true;
                break;
            }
        }
    }

    if (*ada) {
        printf("Nomor makanan tersebut sudah ada.. :(\n");
    } else {
        ID(Info(*var)) = temp;
    }
}

void hapusIdKulkas(infotype * var) {
/* mengembalikan ID makanan yang sementara diubah untuk masuk ke kulkas */

    // KAMUS
    int temp;

    // ALGORITMA
    temp = ID(Info(*var));
    temp = temp/1000;
    ID(Info(*var)) = temp;
}

void ambilDariInventory (Simulator * s, int idx, infotype * var) {
/* prekondisi : idx valid */

    // KAMUS

    // ALGORITMA
    DeleteAt(&Inventory(*s), idx, var);
}

void pindahKeKulkas(infotype var, MatrixKulkas * kulkas, ListDinMakanan * currentNotif, int idX, int idY) {
/* Memindahkan makanan di inventori berdasarkan list of point ke kulkas */
/* prekondisi : list of pointnya sudah valid, dan pada point tersebut slot di kulkasnya kosong */

    // KAMUS

    // ALGORITMA
    ELMTK(*kulkas, idX, idY) = var;
    LOC(Info(var)) = 'K';
    dealocateListMakanan(currentNotif);
    CreateListMakananDin(currentNotif, 100);
    insertLastMakanan(currentNotif, var);
}

void ambilDariKulkas(Simulator * s, int idmakanan, MatrixKulkas * kulkas, ListDinMakanan * currentNotif) {
/* Mengambil makanan dari kulkas dan memasukkannya ke inventory */

    // KAMUS
    int i, j;
    infotype var, dummy;

    // ALGORITMA
    makeDummyInfoType(&dummy);
    for (i = 0; i <= 9; i++) {
        for (j = 0; j <= 19; j++) {
            if (ID(Info(ELMTK(*kulkas, i, j))) == idmakanan) {
                var = ELMTK(*kulkas, i, j);
                ELMTK(*kulkas, i, j) = dummy;
            }
        }
    }
    
    // ubah ID makanan di var
    hapusIdKulkas(&var);

    // masukkan kembali ke inventory
    Enqueue(&Inventory(*s), var);
    dealocateListMakanan(currentNotif);
    CreateListMakananDin(currentNotif, 100);
    insertLastMakanan(currentNotif, var);
}

boolean adjacent(Simulator s, Matrix peta, char c) {
/* Mengecek apakah simulator bersebelahan dengan tempat tertentu */

    // KAMUS
    int x, y;

    // ALGORITMA
    x = Absis(Lokasi(s)); 
    y = Ordinat(Lokasi(s)); 

    if (ELMT_MATRIX(peta, x-1, y) == c) {
        return true;
    } else if (ELMT_MATRIX(peta, x+1, y) == c) {
        return true;
    } else if (ELMT_MATRIX(peta, x, y+1) == c) {
        return true;
    } else if (ELMT_MATRIX(peta, x, y-1) == c) {
        return true;
    } else {
        return false;
    }
}

void displayListMakananAksi(ListStatikM listMakanan, ListStatikM *hasil, int *length, char aksi){
    int i,j;
    createLSMakanan(hasil);
    i=0;
    j=0;
    while(listMakanan.contents[i].id != MARKSTATIK){
        if(listMakanan.contents[i].location == aksi){
            insertFood(hasil, listMakanan.contents[i]);
            j++;
        }
        i++;
    }
    *length = j;
    i=0;
    char *dispAksi;
    switch (aksi) {
        case 'M':
            dispAksi = "MIX";
            break;
        case 'C':
            dispAksi = "CHOP";
            break;
        case 'F':
            dispAksi = "FRY";
            break;
        case 'B':
            dispAksi = "BOIL";
            break;
        default:
            break;
    }

    printf("\n======================\n");
    printf("=        %-4s        =\n", dispAksi);
    printf("======================\n");

    printf("List Bahan Makanan yang Bisa Dibuat:\n");
    while((*hasil).contents[i].id!=MARKSTATIK){
        printf("  [%d] %s\n", i+1,(*hasil).contents[i].name);
        i++;
    }
}

Tree getTreeFromMakanan(Makanan makanan, ListStatikT listResep)
// mendapatkan tree dari sebuah makanan
{
    Tree hasil;
    for(int i=0;i<listResep.elEff;i++){
        if(listResep.list[i]->info == makanan.id){
            hasil = listResep.list[i];
            break;
        }
    }
    return hasil;
}

Makanan getMakananFromId(int id, ListStatikM listMakanan){
    int i=0;
    Makanan hasil;
    while(listMakanan.contents[i].id != MARKSTATIK){
        if(listMakanan.contents[i].id == id){
            hasil = listMakanan.contents[i];
        }
        i++;
    }
    return hasil;
}