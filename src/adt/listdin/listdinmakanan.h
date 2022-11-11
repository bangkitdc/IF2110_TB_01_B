/* File: */

#ifndef LISTDINM_H
#define LISTDINM_H

#include "../../include/boolean.h"
#include "../infotype/infotype.h"
#include "../makanan/makanan.h"
#include "../time/time.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct
{
   infotype *buffer;
   int nEff_Makanan;
   int capacity_Makanan;
} ListDinMakanan;

/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define NEFF_Makanan(l) (l).nEff_Makanan
#define BUFFER_Makanan(l) (l).buffer
#define ELMT_LISTDINAMIS_Makanan(l, i) (l).buffer[i]
#define CAPACITY_LISTDINAMIS_Makanan(l) (l).capacity_Makanan

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListMakananDin(ListDinMakanan *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateListMakanan(ListDinMakanan *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY_LISTDINAMIS_Makanan(l)=0; NEFF_Makanan(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listMakananLengthDinamis(ListDinMakanan l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */


/* ********** TEST KOSONG ********** */
/* *** Test list kosong *** */
boolean isEmptyListMakanan(ListDinMakanan l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */

/* *** Selektor INDEKS *** */
IdxType getFirstIdxS(ListDinMakanan l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdxS(ListDinMakanan l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void printListMakanan(ListDinMakanan l);
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong maka akan ditulis kelayar hasil-hasil dari list tersebut */
/* Jika list kosong : menulis - */
/* Jika tidak kosong, contoh :
    - Ayam goreng berhasil digoreng 
    - Ayam goreng kadaluarsa
    - Ayam berhasil masuk inventory */

void printListMakananUndo(ListDinMakanan l);
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong maka akan ditulis kelayar hasil-hasil dari list tersebut */
/* Jika list kosong : menulis - */
/* Jika tidak kosong, contoh :
    - Ayam goreng tidak jadi digoreng
    - Ayam masuk kembali ke delivery list */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastMakanan(ListDinMakanan *l, infotype val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastMakanan(ListDinMakanan *l, infotype *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListMakanan(ListDinMakanan *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

/* ********* MENYALIN ISI LISTDIN ********* */
void copyListDinMakanan(ListDinMakanan l1, ListDinMakanan * l2);
/* Menyalin elemen di l1 ke l2 */
#endif