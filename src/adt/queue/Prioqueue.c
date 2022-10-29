#include <stdio.h>
#include <stdlib.h>
#include "../../include/boolean.h"
#include "prioqueue.h"
#include "../time/time.h"

/* ********* Prototype ********* */
boolean IsEmptyPrioqueue (PrioQueue Q) {
/* Mengirim true jika Q kosong: lihat definisi di atas */
    
    /* ALGORITMA */
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFullPrioqueue (PrioQueue Q) {
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElPrioqueue */

    /* ALGORITMA */
    return (Tail(Q) + 1 == MaxElPrioqueue(Q));
}

int NBElmtPrioqueue (PrioQueue Q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    
    /* ALGORITMA */
    if (IsEmptyPrioqueue(Q)) {
        return 0;
    } else {
        return(Tail(Q) - Head(Q) + 1);
    }
}

/* *** Kreator *** */
void CreateEmptyPrioqueue (PrioQueue * Q, int Max) {
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElPrioqueue=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

    /* ALGORITMA */
    (*Q).T = (infotype *)malloc((Max + 1) * sizeof(infotype));

    if ((*Q).T == NULL) {
        MaxElPrioqueue(*Q) = 0;
    } else {
        MaxElPrioqueue(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
}

void MakeinfoType (infotype * x, Makanan m) {
/* Membuat makanan m agar bisa dimasukkan kedalam priqueue */
/* I.S. sembarang */
/* F.S. terbuat infotype x yang berisikan data makanan m */

    // KAMUS

    // ALGORITMA
    Time(*x) = TIMEToMenit(EXP(m));
    Info(*x) = m;
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueue * Q) {
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElPrioqueue(Q) diset 0 */

    /* ALGORITMA */
    MaxElPrioqueue(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue1 (PrioQueue * Q, infotype X) {
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas */
    // KAMUS
    int counter, tempidx;

    // ALGORITMA
    if (IsEmptyPrioqueue(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    } else {
        counter = NBElmtPrioqueue(*Q);
        tempidx = Tail(*Q);

        // geser yang timenya > x ke kanan
        while ((Time(X) < Time(Elmt(*Q, tempidx))) && counter > 0) {
            (*Q).T[tempidx + 1] = (*Q).T[tempidx];

            tempidx--;
            counter--;
        }

        (*Q).T[tempidx + 1] = X;
        Tail(*Q) = Tail(*Q) + 1;
    }    
}

void Enqueue (PrioQueue * Q, infotype X) {
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong dan penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas, TAIL "maju"*/

    /* KAMUS */
    PrioQueue temp;
    infotype tempinfo;

    /* ALGORITMA */
    if (IsFullPrioqueue(*Q)) {
        CreateEmptyPrioqueue(&temp, MaxElPrioqueue(*Q));

        // salin ke temp
        while (!IsEmptyPrioqueue(*Q)) {
            Dequeue(Q, &tempinfo);
            Enqueue1(&temp, tempinfo);
        }

        DeAlokasi(Q);
        CreateEmptyPrioqueue(Q, 2 * MaxElPrioqueue(temp));

        // salin kembali ke Q
        while (!IsEmptyPrioqueue(temp)) {
            Dequeue(&temp, &tempinfo);
            Enqueue1(Q, tempinfo);
        }

        // tambahkan X ke Q
        Enqueue1(Q, X);
    } else {
        Enqueue1(Q, X);
    }
}

void Dequeue (PrioQueue * Q, infotype * X) {
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju",  Q mungkin kosong */

    /* ALGORITMA */
    if (NBElmtPrioqueue(*Q) == 1) {
        Info(*X) = Info(InfoHead(*Q));
        Time(*X) = Time(InfoHead(*Q));

        
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Info(*X) = Info(InfoHead(*Q));
        Time(*X) = Time(InfoHead(*Q));

        Head(*Q) += 1;
    }
}

void Delete (PrioQueue * Q, int id, infotype * X) {
/* Proses: Menghapus elemen dengan id x pertama pada Q */
/* I.S. Q tidak mungkin kosong, elemen dengan id harus ada di dalam Q */
/* F.S. elemen X terhapus dari Q, elemen-elemen yang berada di kanan X akan digeser ke kiri */

    // KAMUS
    boolean found;
    infotype temp;
    PrioQueue Q2;

    // ALGORITMA
    found = false;

    CreateEmptyPrioqueue(&Q2, MaxElPrioqueue(*Q));

    while (!found) {
        Dequeue(Q, &temp);
        if (ID(Info(temp)) == id) {
            found = true;
        } else {
            Enqueue(&Q2, temp);
        }
    }

    Info(*X) = Info(temp);
    Time(*X) = Time(temp);

    // kondisi elemen dengan id X telah berada di luar Q
    while (!IsEmptyPrioqueue(*Q)) {
        Dequeue(Q, &temp);
        Enqueue(&Q2, temp);
    }

    DeAlokasi(Q);
    CreateEmptyPrioqueue(Q, MaxElPrioqueue(Q2));

    // salin kembali dari Q2 ke Q
    while (!IsEmptyPrioqueue(Q2)) {
        Dequeue(&Q2, &temp);
        Enqueue(Q, temp);
    }
}

void CopyQueue (PrioQueue *Q1, PrioQueue * Q2) {
/* Proses: Menyalin elemen-elemen Q1 ke Q2 */
/* I.S. Q1 mungkin kosong */
/* F.S. Q2 terisi oleh elemen-elemen dari Q2 dengan urutan yang sama */

    // KAMUS
    infotype temp;
    PrioQueue Qtemp;

    // ALGORITMA
    CreateEmptyPrioqueue(&Qtemp, MaxElPrioqueue(*Q1));

    // menyalin elemen Q1 ke Q2
    while (!IsEmptyPrioqueue(*Q1)) {
        Dequeue(Q1, &temp);
        Enqueue(&Qtemp, temp);
        Enqueue(Q2, temp);
    } 

    // menyalin kembali elemen dari Qtemp ke Q1
    while (!IsEmptyPrioqueue(Qtemp)) {
        Dequeue(&Qtemp, &temp);
        Enqueue(Q1, temp);
    }
}

/* Operasi Tambahan */
void PrintPrioQueue (PrioQueue Q) {
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
    List Makanan di Inventory
    (nama - waktu sisa kedaluwarsa)
    makanan1 - x menit
    makanan2 - y menit
    dst
*/

    /* KAMUS */
    infotype temp;
    int ctr;

    /* ALGORITMA */
    printf("List Makanan di Inventory\n");
    printf("(nama - waktu sisa kedaluwarsa)\n");

    ctr = 1;
    while (!IsEmptyPrioqueue(Q)) {
        Dequeue(&Q, &temp);
        printf("%d. %s - %ld menit\n", ctr, NAME(Info(temp)), Time(temp)); // dijadiin nama makanan dulu
        ctr++;
    }

    if (ctr == 1) {
        printf("Inventorynya kosong.. :(\n");
    }
}

/* Operasi untuk mengurus inventory dan delivery list */
void PasstimeQueue(PrioQueue * Q, int x) {
/* Mengurangi waktu tiap elemen di queue */
/* I.S. Q mungkin kosong */
/* F.S. setiap elemen di Q waktunya berkurang sesuai dengan jumlah waktu yang telah berlalu, jika waktunya menjadi 0 maka elemen tersebut akan dihapus dari queue */

    // KAMUS
    int i, ctr;
    PrioQueue temp;
    infotype tempvar;
    boolean kadaluarsa;

    // ALGORITMA 
    CreateEmptyPrioqueue(&temp, MaxElPrioqueue(*Q));
    kadaluarsa = false;
    ctr = 1;
    printf("Notifikasi: ");
    // looping setiap menit
    for (i = 1; i <= x; i++) {
        while (!IsEmptyPrioqueue(*Q)) {
            Dequeue(Q, &tempvar);
            Time(tempvar)--;
            if (Time(tempvar) == 0) {
                kadaluarsa = true;

                if (ctr == 1) {
                    printf("\n");
                }

                printf("%d. %s kedaluwarsa.. :(\n", ctr, NAME(Info(tempvar)));
                ctr++;
            } else {
                Enqueue(&temp, tempvar);
            }
        }

        // salin kembali dari temp ke Q
        CopyQueue(&temp, Q);
        DeAlokasi(&temp);
        CreateEmptyPrioqueue(&temp, MaxElPrioqueue(*Q));
    }

    if (!kadaluarsa) {

        printf("-\n");
    }
}

void PassTimeDelivery(PrioQueue * deliList, PrioQueue * destination, int x) {
/* Mengurangi waktu tiap elemen di queue */
/* I.S. Q mungkin kosong */
/* F.S. setiap elemen di Q waktunya berkurang sesuai dengan jumlah waktu yang telah berlalu, jika waktunya menjadi 0 maka elemen tersebut akan dihapus dari delivery list dan dipindahkan ke inventory */

    // KAMUS
    int i;
    PrioQueue temp;
    infotype tempvar;

    // ALGORITMA 
    CreateEmptyPrioqueue(&temp, MaxElPrioqueue(*deliList));

    // looping setiap menit
    for (i = 1; i <= x; i++) {
        while (!IsEmptyPrioqueue(*deliList)) {
            Dequeue(deliList, &tempvar);
            Time(tempvar)--;
            if (Time(tempvar) == 0) {
                Time(tempvar) = TIMEToMenit(EXP(Info(tempvar)));
                Enqueue(destination, tempvar);
            } else {
                Enqueue(&temp, tempvar);
            }
        }

        // salin kembali dari temp ke Q
        CopyQueue(&temp, deliList);
        DeAlokasi(&temp);
        CreateEmptyPrioqueue(&temp, MaxElPrioqueue(*deliList));
    }
}