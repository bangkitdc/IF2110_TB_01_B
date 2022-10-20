// Nama: Muhammad Bangkit Dwi Cahyono
// NIM: 13521055

/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#include "boolean.h"
#include <stdio.h>
#include "liststatik.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */
   
   // KAMUS LOKAL
   int i;

   // ALGORITMA
   for (i = 0; i < CAPACITY; i ++) {
      ELMT(*l, i) = MARK;
   }
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

   // KAMUS LOKAL
   int i = 0;

   // ALGORITMA
   while (i < CAPACITY && ELMT(l, i) != MARK) {
      i += 1;
   }
   // ELMT(l, i) == MARK
   return i;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */

   // ALGORITMA
   return (IDX_MIN);
}

IdxType getLastIdx(ListStatik l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

   // ALGORITMA
   return (listLength(l) - 1);
}


/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/

   // ALGORITMA
   return (i >= 0 && i < CAPACITY);
}

boolean isIdxEff(ListStatik l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

   // ALGORITMA
   return (i >= 0 && i < listLength(l));
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */

   // ALGORITMA
   return (!listLength(l));
}

boolean isFull(ListStatik l){
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

   // ALGORITMA
   return (listLength(l) == CAPACITY);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l){
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */

   // KAMUS LOKAL
   int i, n;

   // ALGORITMA
   scanf("%d", &n);
   while (!(0 <= n && n <= CAPACITY)) {
      scanf("%d", &n);
   }
   CreateListStatik(l);
   if (n > 0) {
      for (i = 0; i < n; i ++) {
         scanf("%d", &ELMT(*l, i));
      }
   }
}

void printList(ListStatik l){
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

   // KAMUS LOKAL
   int i;

   // ALGORITMA
   printf("[");
   if (listLength(l) > 0) {
      printf("%d", ELMT(l, 0));
      for (i = 1; i < listLength(l); i ++) {
         printf(",%d", ELMT(l, i));
      }
   }
   printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */ 

   // KAMUS LOKAL
   int i;
   // Karena local memory yang dipakai, dapat memanfaatkan l1

   // ALGORITMA
   if (plus) {
      for (i = 0; i < listLength(l1); i ++) {
         ELMT(l1, i) += ELMT(l2, i);
      }
   } else {
      for (i = 0; i < listLength(l1); i ++) {
         ELMT(l1, i) -= ELMT(l2, i);
      }
   }
   return l1;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */ 

   // KAMUS LOKAL
   int i = 0;
   boolean flag = true;

   // ALGORITMA
   if (listLength(l1) != listLength(l2)) {
      flag = false;
   } else {
      while (i < listLength(l1) && flag) {
         if (ELMT(l1, i) != ELMT(l2, i)) {
            flag = false;
         }
         i += 1;
      }
   }
   return flag;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

   // KAMUS LOKAL
   int i = 0;
   boolean found = false;

   // ALGORITMA
   while(i < listLength(l) && !found) {
      if (ELMT(l, i) == val) {
         found = true;
      } else {
         i += 1;
      }
   }
   return (
      (found) ? i : IDX_UNDEF
   );
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

   // KAMUS LOKAL
   int i;

   // ALGORITMA
   *max = ELMT(l, 0);
   *min = ELMT(l, 0);
   for (i = 0; i < listLength(l); i ++) {
      if (ELMT(l, i) > *max) {
         *max = ELMT(l, i);
      }
      if (ELMT(l, i) < *min) {
         *min = ELMT(l, i);
      }
   }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val){
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */

   // KAMUS LOKAL
   int i;

   // ALGORITMA
   for (i = listLength(*l); i > 0; i --) {
      ELMT(*l, i) = ELMT(*l, i - 1);
   }
   ELMT(*l, 0) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx){
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */

   // KAMUS LOKAL
   int i;

   // ALGORITMA
   for (i = listLength(*l); i > idx; i --) {
      ELMT(*l, i) = ELMT(*l, i - 1);
   }
   ELMT(*l, idx) = val;
}

void insertLast(ListStatik *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

   // ALGORITMA
   ELMT(*l, listLength(*l)) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val){
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

   // KAMUS LOKAL
   int i;

   // ALGORITMA
   *val = ELMT(*l, 0);
   for (i = 0; i < listLength(*l) - 1; i ++) { //Geser kiri
      ELMT(*l, i) = ELMT(*l, i + 1);
   }
   ELMT(*l, listLength(*l) - 1) = MARK;
}

/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx){
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

   // KAMUS LOKAL
   int i;

   // ALGORITMA 
   *val = ELMT(*l, idx);
   for (i = idx; i < listLength(*l) - 1; i ++) {
      ELMT(*l, i) = ELMT(*l, i + 1);
   }
   ELMT(*l, listLength(*l) - 1) = MARK;
}

/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val){
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

   // ALGORITMA
   *val = ELMT(*l, listLength(*l) - 1);
   ELMT(*l, listLength(*l) - 1) = MARK;
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

   // KAMUS LOKAL
   int i, j;
   ElType temp;
   boolean flag = false;

   // ALGORITMA
   // Optimized Bubble Sort <3
   for (i = 0; i < listLength(*l) - 1; i ++) {
      for (j = i + 1; j < listLength(*l); j ++) {
         if (
            (asc && ELMT(*l, i) > ELMT(*l, j)) ||
            (!asc && ELMT(*l, i) < ELMT(*l, j))
         ) {
            temp = ELMT(*l, i);
            ELMT(*l, i) = ELMT(*l, j);
            ELMT(*l, j) = temp;
            flag = true;
         }
      }
      if (!flag) { 
         break;
      }
   }
}
