/* File : Prioqueue.h */
/* Definisi Prioqueue */
/* Dengan pendekatan list dinamik, serta queuenya tidak sirkuler dan rata kiri */

#ifndef prioqueue_H
#define prioqueue_H

#include "../../utility/boolean.h"
#include "../time/time.h"
#include "../makanan/makanan.h"

#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef struct {
    long time;              /* berisi waktu dalam menit */
    Makanan info;           /* makanan */
} infotype;
typedef int address;        /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    infotype * T;           /* tabel penyimpan elemen */
    address HEAD;           /* alamat penghapusan */
    address TAIL;           /* alamat penambahan */
    int MaxElPrioqueue;     /* Max elemen queue */
} PrioQueue;
/* Definisi PrioQueue kosong: HEAD=Nil; TAIL=Nil. (saat pertama kali didefinisikan) */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueue, maka akses elemen : */
#define Time(e)             (e).time
#define Info(e)             (e).info
#define Head(Q)             (Q).HEAD
#define Tail(Q)             (Q).TAIL
#define InfoHead(Q)         (Q).T[(Q).HEAD]
#define InfoTail(Q)         (Q).T[(Q).TAIL]
#define MaxElPrioqueue(Q)   (Q).MaxElPrioqueue
#define Elmt(Q,i)           (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmptyPrioqueue (PrioQueue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullPrioqueue (PrioQueue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElPrioqueue */
int NBElmtPrioqueue (PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElPrioqueue=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

void MakeinfoType (infotype * x, Makanan m);
/* Membuat makanan m agar bisa dimasukkan kedalam priqueue */
/* I.S. sembarang */
/* F.S. terbuat infotype x yang berisikan data makanan m */

/* *** Destruktor *** */
void DeAlokasi(PrioQueue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElPrioqueue(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue1 (PrioQueue * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas */

void Enqueue (PrioQueue * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q boleh penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas, jika prio queuenya penuh maka prio queuenya akan dialokasi terlebih dahulu dan kemudian ditambahkan */

void Dequeue (PrioQueue * Q, infotype * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju", Q mungkin kosong */

void Delete (PrioQueue * Q, int id, infotype * X) ;
/* Proses: Menghapus elemen dengan id x pertama pada Q */
/* I.S. Q tidak mungkin kosong, elemen dengan id harus ada di dalam Q */
/* F.S. elemen X terhapus dari Q, elemen-elemen yang berada di kanan X akan digeser ke kiri */

void CopyQueue (PrioQueue *Q1, PrioQueue * Q2);
/* Proses: Menyalin elemen-elemen Q1 ke Q2 */
/* I.S. Q1 mungkin kosong */
/* F.S. Q2 terisi oleh elemen-elemen dari Q2 dengan urutan yang sama */

/* Operasi Tambahan */
void PrintPrioQueue (PrioQueue Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/

void PasstimeQueue(PrioQueue * Q, int x);
/* Mengurangi waktu tiap elemen di queue */
/* I.S. Q mungkin kosong */
/* F.S. setiap elemen di Q waktunya berkurang sesuai dengan jumlah waktu yang telah berlalu, jika waktunya menjadi 0 maka elemen tersebut akan dihapus dari queue */

#endif
