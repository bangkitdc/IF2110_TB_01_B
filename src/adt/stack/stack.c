#include <stdio.h>
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S) {
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxStack */
/* jadi indeksnya antara 0.. MaxStack */
/* Ciri stack kosong : TOP bernilai Nil */
    Top(*S) = Nil;

}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stack S) {
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    return (Top(S) == Nil);
}
boolean IsStackFull(Stack S) {
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return (Top(S) == MaxStack - 1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, State X) {
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    Top(*S) = Top(*S) + 1;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, State* X) {
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    *X = InfoTop(*S);
    Top(*S) = Top(*S) - 1;
}

void EmptyStack(Stack * S) {
/* Mengosongkan S sehingga stack S kosong */
/* I.S. S tidak mungkin kosong */
/* F.S. S kosong */
    State temp;
    while (!IsStackEmpty(*S)) {
        Pop(S, &temp);
    }
}

void Undo(Stack * SMain, Stack * SSecondary, State * currentState) {
/* Meng-undo aksi pada SMain */
/* I.S. SMain tidak boleh kosong */   
/* F.S. Elemen TOP pada SMain telah di-pop, dan elemen tersebut dipush ke SSecondary. currentState diassign state yang di-undo */
    State temp;

    Push(SSecondary, *currentState);
    Pop(SMain, &temp);
    *currentState = temp;    
}

void Redo(Stack * SMain, Stack * SSecondary, State * currentState) {
/* Meng-redo aksi pada SMain */
/* I.S. SSecondary tidak boleh kosong */
/* F.S. Elemen TOP pada SSecondary telah di-pop, dan elemen tersebut dipush ke SMain. currentState diassign state yang di-redo */
/* Stack SSecondary dikosongkan */
    State temp;

    Push(SMain, *currentState);
    Pop(SSecondary, &temp);
    *currentState = temp;
}