#include <stdio.h>
#include "simulator.h"

/* PRIMITIF SIMULATOR*/
void createSimulator(Simulator* s, char* Username, POINT lokasi, PrioQueue inventory) {
/* Mengassign simulator */

    // ALGORITMA
    gantiUser(s, Username);
    gantiLokasi(s, lokasi);
    setInventory(s, inventory);
}

void gantiUser(Simulator * s, char* username) {
/* Mengganti username */

    // KAMUS
    int i;

    // ALGORITMA
    Username(*s) = username;
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

State simulatorToState(Simulator s, TIME currentTime, ListDinMakanan currentNotif, MatrixKulkas currentKulkas) {
/* mengkonversi simulator s ke State*/
/* digunakan saat mau menyimpan State ke stack */

    // KAMUS
    State temp;

    // ALGORITMA
    InfoWaktu(temp) = currentTime;
    InfoKoordinat(temp) = Lokasi(s);
    InfoInventory(temp) = Inventory(s);
    InfoNotif(temp) = currentNotif;
    InfoKulkas(temp) = currentKulkas;

    return temp;
}

void loadState(Simulator * s, State st, TIME * currentTime, char * currentUsername, ListDinMakanan * currentNotif, MatrixKulkas * currentKulkas) {
/* mengkonversi State dari stack ke simulator dan menyimpannya di simulator */
/* digunakan saat undo dan redo */

    // ALGORITMA
    createSimulator(s, currentUsername, InfoKoordinat(st), InfoInventory(st));
    *currentTime = InfoWaktu(st);
    *currentNotif = InfoNotif(st);
    *currentKulkas = InfoKulkas(st);
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

void pindahKeKulkas(Simulator * s, int idx, MatrixKulkas * kulkas, ListDinMakanan * currentNotif) {
/* Memindahkan makanan di inventori dengan index idx ke kulkas */

    // KAMUS
    infotype temp;
    int i, j;
    boolean moved;

    // ALGORITMA
    DeleteAt(&Inventory(*s), idx, &temp);

    moved = false;
    for (i = 0; i <= getLastIdxRowKulkas(*kulkas); i++) {
        for (j = 0; j <= getLastIdxColKulkas(*kulkas); j++) {
            if (cekSpotKosongKulkas(*kulkas, i, j)) {
                moved = true;
                break;
            }
        }

        if (moved) {
            break;
        }
    }

    if (!moved) {
        Enqueue(&Inventory(*s), temp);
        printf("kulkas sudah penuh :(\n");
    } else {
        ELMTK(*kulkas, i, j) = temp;
        LOC(Info(temp)) = 'K';
        insertLastMakanan(currentNotif, temp);
    }
}

void ambilDariKulkas(Simulator * s, MatrixKulkas * kulkas, int idxX, int idxY, ListDinMakanan * currentNotif) {
/* Mengambil makanan dari kulkas dan memasukkannya ke inventory */

    // KAMUS
    infotype dummy, temp;

    // ALGORITMA
    makeDummyInfoType(&dummy);
    if (cekSpotKosongKulkas(*kulkas, idxX, idxY)) {
        printf("Tidak ada makanan di slot itu.. :(\n");
    } else {
        temp = ELMTK(*kulkas, idxX, idxY);
        ELMTK(*kulkas, idxX, idxY) = dummy;
        Enqueue(&Inventory(*s), temp);
        LOC(Info(temp)) = 'k';
        insertLastMakanan(currentNotif, temp);
    }

}

boolean adjacent(Simulator s, Matrix m, char x) {
/* Mengecek apakah simulator bersebelahan dengan tempat tertentu */

    // ALGORITMA

}

void displayListMakananAksi(ListStatikM listMakanan, ListStatikM *hasil, char aksi){
    int i;
    createLSMakanan(hasil);
    i=0;
    while(listMakanan.contents[i].id != MARKSTATIK){
        if(listMakanan.contents[i].location == aksi){
            insertFood(hasil, listMakanan.contents[i]);
        }
    }
    i=0;
    while((*hasil).contents[i].id!=MARKSTATIK){
        printf("%d. %s\n", i+1,(*hasil).contents[i].name);
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

void mengolahMakanan(Makanan makananOlah, PrioQueue *inventory, ListStatikT listResep, ListStatikM listMakanan, char lokasiAksi){
    Tree treeMakananOlah;
    infotype tmp;
    int id, idBahan[10];
    boolean bisa, ada;

    treeMakananOlah = getTreeFromMakanan(makananOlah, listResep);
    bisa = false;
    for(int i=0;i<treeMakananOlah->childEff;i++){            //menelusuri tiap bahan makanan
        idBahan[i] = treeMakananOlah->children[i]->info;
        id = treeMakananOlah->children[i]->info;
        ada = false;

        for(int j=(*inventory).HEAD;j<=(*inventory).TAIL;j++){    // mencari apakah ada bahan pada inventori
            if(id == (*inventory).T[j].info.id){
                ada = true;
            }
        }

        if(ada){           
            idBahan[i] = -1;
            if(i==0){
                bisa = true;
            }
        }else{
            bisa = false;
        }
    }

    if(bisa){                                        // jika bisa dibuat
        for(int i=0;i<treeMakananOlah->childEff;i++){
            Delete(inventory, treeMakananOlah->children[i]->info, &tmp);
        }
        tmp.info = makananOlah;
        tmp.time = TIMEToMenit(makananOlah.expiry);
        Enqueue(inventory, tmp);
        printf("%s selesai dibuat dan sudah masuk inventory!\n", makananOlah.name);
    }else{                                           // jika tidak bisa dibuat
        printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut:\n", makananOlah.name);
        for(int i=0;i<treeMakananOlah->childEff;i++){
            if(idBahan[i]!=-1){
                int j;
                while (listMakanan.contents[j].id != MARKSTATIK){
                    if(id == listMakanan.contents[j].id){
                        printf("   %d. %s\n", i+1, listMakanan.contents[j].name);
                    }
                }
            }
        }
    }
}