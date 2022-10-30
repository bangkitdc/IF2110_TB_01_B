#include <stdio.h>
#include "../../include/boolean.h"
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S) {
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S) {
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    return (Top(S) == Nil);
}
boolean IsFull(Stack S) {
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return (Top(S) == MaxEl - 1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, state X) {
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    Top(*S) = Top(*S) + 1;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, state* X) {
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    *X = InfoTop(*S);
    Top(*S) = Top(*S) - 1;
}

void Undo(Stack * SMain, Stack * SSecondary) {
/* Meng-undo aksi pada SMain */
/* I.S. SMain tidak boleh kosong */
/* F.S. Elemen TOP pada SMain telah di-pop, dan elemen tersebut dipush ke SSecondary */
    state temp;
    Pop(SMain, *temp);
    Push(SSecondary, temp);    
}

void Redo(Stack * SMain, Stack * SSecondary) {
/* Meng-redo aksi pada SMain */
/* I.S. SSecondary tidak boleh kosong */
/* F.S. Elemen TOP pada SSecondary telah di-pop, dan elemen tersebut dipush ke SMain */
    state temp;
    Pop(SSecondary, *temp);
    Push(SMain, temp);
}