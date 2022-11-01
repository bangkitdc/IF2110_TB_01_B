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

void gerakUser(Simulator * s, char x) {
/* Menggerakkan user */

    // KAMUS
    POINT temp;

    // ALGORITMA
    // pakai wasd
    if (x == 'w') {
        temp = MoveN(Lokasi(*s));
        gantiLokasi(s, temp);
    } else if (x == 'a') {
        temp = MoveW(Lokasi(*s));
        gantiLokasi(s, temp);
    } else if (x == 'd') {
        temp = MoveE(Lokasi(*s));
        gantiLokasi(s, temp);
    } else if (x == 's') {
        temp = MoveS(Lokasi(*s));
        gantiLokasi(s, temp);
    }
}

State simulatorToState(Simulator s, TIME currentTime) {
/* mengkonversi simulator s ke State*/
/* digunakan saat mau menyimpan State ke stack */

    // KAMUS
    State temp;

    // ALGORITMA
    InfoWaktu(temp) = currentTime;
    InfoKoordinat(temp) = Lokasi(s);
    InfoInventory(temp) = Inventory(s);

    return temp;
}

void loadState(Simulator * s, State st, TIME * currentTime, char * currentUsername) {
/* mengkonversi State dari stack ke simulator dan menyimpannya di simulator */
/* digunakan saat undo dan redo */

    // ALGORITMA
    createSimulator(s, currentUsername, InfoKoordinat(st), InfoInventory(st));
    *currentTime = InfoWaktu(st);
}

void setInventory(Simulator * s, PrioQueue inventory) {
/* mengassign inventory di awal */

    // ALGORITMA
    Inventory(*s) = inventory;
}

void pindahKeKulkas(Simulator * s, int id) {
/* Memindahkan makanan di inventori ke kulkas */

    // KAMUS

    // ALGORITMA
    
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
            if(idBahan!=-1){
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