/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "../../include/boolean.h"
#include "../time/time.h"
#include "../makanan/makanan.h"
#include "../point/point.h"
#include "../queue/prioqueue.h"
#include "../matrix/matrixKulkas.h"
#include "../listdin/listdinmakanan.h"
#include "../liststatik/liststatikM.h"

#define Nil -1
#define MaxStack 1000
/* Nil adalah stack dengan elemen kosong . */

typedef struct {
  TIME waktu; // Waktu terkini
  POINT koordinat; // Posisi simulator
  PrioQueue inventory; // Prioqueue berupa makanan dalam inventory yang disertai waktu expired
  MatrixKulkas kulkas; // Isi kulkas terkini
  ListDinMakanan listMakanan; // List makanan yang berubah (misal abis di-FRY/di-BOIL/kedaluarsa)
} State; // State yang disimpan di dalam stack
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  State T[MaxStack]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxStack-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define InfoWaktu(X) (X).waktu
#define InfoKoordinat(X) (X).koordinat
#define InfoInventory(X) (X).inventory
#define InfoKulkas(X) (X).kulkas
#define InfoNotif(X) (X).listmakanan

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxStack */
/* jadi indeksnya antara 0.. MaxStack */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, State X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, State* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void EmptyStack(Stack * S);
/* Mengosongkan S sehingga stack S kosong */
/* I.S. S tidak mungkin kosong */
/* F.S. S kosong */

void Undo(Stack * SMain, Stack * SSecondary, State * currentState);
/* Meng-undo aksi pada SMain */
/* I.S. SMain tidak boleh kosong */
/* F.S. Elemen TOP pada SMain telah di-pop, dan elemen tersebut dipush ke SSecondary */

void Redo(Stack * SMain, Stack * SSecondary, State * currentState);
/* Meng-redo aksi pada SMain */
/* I.S. SSecondary tidak boleh kosong */
/* F.S. Elemen TOP pada SSecondary telah di-pop, dan elemen tersebut dipush ke SMain */

#endif