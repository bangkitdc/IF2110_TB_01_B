/* File: */

#include <stdio.h>
#include "listdin.h"
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
    BUFFER(*l) = malloc (capacity*sizeof(ElType));
}

void dealocateList(ListDin *l){
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    free(BUFFER(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    return 0;
}
IdxType getLastIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return NEFF(l)-1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (i >= 0 && i < CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
    return (i >= 0 && i < NEFF(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
    return (NEFF(l) == 0);
}
boolean isFull(ListDin l){
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return (NEFF(l) == CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
    int n = IDX_UNDEF;
    while (n<0 || n>CAPACITY(*l)){
        scanf("%d", &n);
    }
    int j, x;
    NEFF(*l) = n;
    if (n){
        for(j=0;j<n;j++){
            scanf("%d", &x);
            ELMT(*l,j) = x;
        }
    }
}
void printList(ListDin l){
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
    int i;
    printf("[");
    for (i = 0; i < listLength(l); i++){
        if (i == listLength(l)-1) {
            printf("%d", ELMT(l,i));
        } else {
            printf("%d,", ELMT(l,i));
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
    ListDin Lsem;
    CreateListDin(&Lsem, listLength(l1));
    int i;
    if (plus == true) {
        for (i = 0; i < listLength(l1); i++){
            ELMT(Lsem,i) = ELMT(l1,i) + ELMT(l2,i);
        }
    } else {
        for (i = 0; i < listLength(l1); i++){
            ELMT(Lsem,i) = ELMT(l1,i) - ELMT(l2,i);
            }
        }
    return Lsem;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
    int i = 0;
    boolean cek = true;
    if (listLength(l1) == listLength(l2)){
        while (cek == true && i < listLength(l1)){
            if (ELMT(l1,i) != ELMT(l2,i)){
                cek = false;
            }
            i += 1;
        }
    }
    return cek;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
    int i = 0;
    boolean cek = true;
    while (cek == true && i < listLength(l)) {
        if (ELMT(l,i) == val) {
            cek = false;
        }
        i += 1;
    }
    if (cek == true) {
        return IDX_UNDEF;
    } else {
        return i;
    }
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
    int i;
    for (i = 0; i < listLength(l); i++){
        if (ELMT(l,i) < *min){
            *min = ELMT(l,i);
        } if (ELMT(l,i) > *max){
            *max = ELMT(l,i);
        }
    }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
    int i;
    CreateListDin(lOut,CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (i = 0; i < listLength(lIn); i++){
        ELMT(*lOut,i) = ELMT(lIn,i);
    }
}
ElType sumList(ListDin l){
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
    ElType jml = 0;
    int i, n;
    n = listLength(l);
    for (i = 0; i < n; i++){
        jml += ELMT(l,i);
    }
    return jml;
}
int countVal(ListDin l, ElType val){
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
    int jml = 0;
    int i, n;
    n = listLength(l);
    for (i = 0; i < n; i++){
        if (ELMT(l,i) == val) {
            jml += 1;
        }
    }
    return jml;
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
    int n = listLength(*l);
    int i, j, position, tmp;   
    if(asc){
        for (i = 0; i < (n - 1); i++) {
            position = i;
            for (j = i + 1; j < n; j++) {
                if (ELMT(*l,position) > ELMT(*l,j))
                    position = j;
            }
            if (position != i) {
                tmp = ELMT(*l,i);
                ELMT(*l,i) = ELMT(*l,position);
                ELMT(*l,position) = tmp;
            }
        }        
    }
    else{
        for (i = 0; i < (n - 1); i++) {
            position = i;
            for (j = i + 1; j < n; j++) {
                if (ELMT(*l,position) < ELMT(*l,j))
                    position = j;
            }
            if (position != i) {
                tmp = ELMT(*l,i);
                ELMT(*l,i) = ELMT(*l,position);
                ELMT(*l,position) = tmp;
            }
        }  
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l) += 1;
}
void deleteLast(ListDin *l, ElType *val){
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = ELMT(*l,listLength(*l)-1);
    NEFF(*l) -= 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num){
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    CAPACITY(*l) += num;
    BUFFER(*l) = realloc (BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}

void shrinkList(ListDin *l, int num){
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    CAPACITY(*l) -= num;
    BUFFER(*l) = realloc (BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}

void compressList(ListDin *l){
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
    CAPACITY(*l) = NEFF(*l);
    BUFFER(*l) = realloc (BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}