#include <stdio.h>
#include <stdlib.h>
#include "../../include/boolean.h"
#include "prioqueue.h"
#include "../../utility/color/color.h"

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
        while (TLT(Time(X), Time(Elmt(*Q, tempidx))) && counter > 0) {
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

void DeleteAt (PrioQueue * Q, int idx, infotype * X) {
/* Menghapus elemen dengan index idx pada queue */
/* I.S. Q pasti tidak kosong, dan idx adalah index yang valid dari Q */
/* F.S. elemen dengan index idx terhapus dari Q dan disimpan di X */

    // KAMUS
    PrioQueue temp;
    infotype tempvar;
    int i;

    // ALGORITMA
    CreateEmptyPrioqueue(&temp, MaxElPrioqueue(*Q));
    CopyQueue(Q, &temp);

    DeAlokasi(Q);
    CreateEmptyPrioqueue(Q, MaxElPrioqueue(temp));

    i = 0;
    while (!IsEmptyPrioqueue(temp)) {
        if (i == idx) {
            Dequeue(&temp, X);
        } else {
            Dequeue(&temp, &tempvar);
            Enqueue(Q, tempvar);
        }

        i++;
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
    makanan1 - x hari y jam z menit
    makanan2 - y menit
    dst
*/

    /* KAMUS */
    infotype temp;
    int ctr;

    /* ALGORITMA */
    if (IsEmptyPrioqueue(Q)) {
        sprintRed("\nInventorynya kosong.. :(\n");
    } else {
        sprintCyan("         \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 INVENTORY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("===============================================\n");
        printf("No  Nama                Expired In             \n"); // TABLE TITLES !
        printf("===============================================\n");
        
        ctr = 1;
        while (!IsEmptyPrioqueue(Q))
        {
            Dequeue(&Q, &temp);
            printf("%2d  %-16s\t", ctr, NAME(Info(temp))); // dijadiin nama makanan dulu
            TulisTIME2(Time(temp));
            printf("\n");
            ctr++;
        }
    }
}

void PrintPrioQueueDelivery (PrioQueue Q) {
/* Mencetak isi Delivery list */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
    List Makanan di Perjalanan
    (nama - waktu sisa delivery)
    makanan1 - x hari y jam z menit
    makanan2 - y menit
    dst
*/

    /* KAMUS */
    infotype temp;
    int ctr;

    /* ALGORITMA */
    if (IsEmptyPrioqueue(Q)) {
        sprintRed("\nDelivery list kosong.. :(\n");
    } else {
        sprintCyan("\n============ Makanan sedang OTW ==========\n");
        printf("(nama - waktu sisa delivery)\n");

        ctr = 1;
        while (!IsEmptyPrioqueue(Q)) {
            Dequeue(&Q, &temp);
            printf("  [%d] %s - ", ctr, NAME(Info(temp))); // dijadiin nama makanan dulu
            TulisTIME2(Time(temp));
            printf("\n");
            ctr++;
        }
    }
}
/* Operasi untuk mengurus inventory dan delivery list */
void PasstimeQueue(PrioQueue * Q, int x, ListDinMakanan * notif) {
/* Mengurangi waktu tiap elemen di queue */
/* I.S. Q mungkin kosong */
/* F.S. setiap elemen di Q waktunya berkurang sesuai dengan jumlah waktu yang telah berlalu, jika waktunya menjadi 0 maka elemen tersebut akan dihapus dari queue */

    // KAMUS
    int i;
    PrioQueue temp;
    infotype tempvar;

    // ALGORITMA 
    CreateEmptyPrioqueue(&temp, MaxElPrioqueue(*Q));
    // looping setiap menit
    for (i = 1; i <= x; i++) {
        while (!IsEmptyPrioqueue(*Q)) {
            Dequeue(Q, &tempvar);
            Time(tempvar) = PrevMenit(Time(tempvar));
            if (TIMEToMenit(Time(tempvar)) == 0) {
                insertLastMakanan(notif, tempvar);
            } else {
                Enqueue(&temp, tempvar);
            }
        }

        // salin kembali dari temp ke Q
        DeAlokasi(Q);
        CreateEmptyPrioqueue(Q, MaxElPrioqueue(temp));
        CopyQueue(&temp, Q);
        DeAlokasi(&temp);
        CreateEmptyPrioqueue(&temp, MaxElPrioqueue(*Q));
    }
}

void PassTimeDelivery(PrioQueue * deliList, PrioQueue * destination, int x, ListDinMakanan * notif) {
/* Mengurangi waktu tiap elemen di queue */
/* I.S. Q mungkin kosong */
/* F.S. setiap elemen di Q waktunya berkurang sesuai dengan jumlah waktu yang telah berlalu, jika waktunya menjadi 0 maka elemen tersebut akan dihapus dari delivery list dan dipindahkan ke inventory */

    // KAMUS
    int i;
    PrioQueue temp;
    infotype tempvar;
    TIME temptime;

    // ALGORITMA 
    CreateEmptyPrioqueue(&temp, MaxElPrioqueue(*deliList));
    CreateTime(&temptime, 0, 0, 0);

    // looping setiap menit
    for (i = 1; i <= x; i++) {
        while (!IsEmptyPrioqueue(*deliList)) {
            Dequeue(deliList, &tempvar);
            Time(tempvar) = PrevMenit(Time(tempvar));
            // TulisTIME(Time(tempvar));
            if (TIMEToMenit(Time(tempvar)) == 0) {
                Time(tempvar) = EXP(Info(tempvar));
                DELIVERY(Info(tempvar)) = temptime;
                LOC(Info(tempvar)) = 'T';
                Enqueue(destination, tempvar);
                insertLastMakanan(notif, tempvar);
            } 
            else {
                Enqueue(&temp, tempvar);
            }
        }

        // salin kembali dari temp ke Q
        DeAlokasi(deliList);
        CreateEmptyPrioqueue(deliList, MaxElPrioqueue(temp));
        if (!IsEmptyPrioqueue(temp)) {
            CopyQueue(&temp, deliList);
        }
        DeAlokasi(&temp);
        CreateEmptyPrioqueue(&temp, MaxElPrioqueue(*deliList));
    }
}

/* Pengakses */
int IndexOfPrioqueue(PrioQueue Q, infotype x) {
/* Menghasilkan index dimana x pertama kali ditemukan di Q */
/* I.S. Q mungkin kosong, dan x tidak ada di list */
/* F.S. dihasilkan index elemen x di Q, indexnya = -1 jika tidak ditemukan di list */

    // KAMUS
    int idx;
    PrioQueue temp;
    boolean found;
    infotype tempvar;

    // ALGORITMA
    CreateEmptyPrioqueue(&temp, MaxElPrioqueue(Q));
    CopyQueue(&Q, &temp);

    found = false;
    idx = 0;
    while (!found && !IsEmptyPrioqueue(temp)) {
        if (TEQ(Time(InfoHead(temp)), Time(x)) && ID(Info(InfoHead(temp))) == ID(Info(x))) {
            found = true;
        } else {
            idx++;
            Dequeue(&temp, &tempvar);
        }
    }

    if (found) {
        return idx;
    } else {
        return -1;
    }
}

infotype GetElmtPrioqueue(PrioQueue Q, int idx) {
/* Menghasilkan elemen dengan index idx di Q */
/* I.S. Q mungkin kosong, elemen pasti ada di Q dan indexnya valid */
/* F.S. elemen dengan index idx di Q */

    // KAMUS

    // ALGORITMA
    return Elmt(Q, idx);
}