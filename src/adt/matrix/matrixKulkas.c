/* ********** Definisi TYPE MatrixKulkas dengan Index dan elemen integer ********** */
#include <stdio.h>
#include "../../include/boolean.h"
#include "matrixKulkas.h"

/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP_K-1][0..COL_CAP_K-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MatrixKulkas *** */
void createMatrixKulkas(int nRows, int nCols, MatrixKulkas *m)
/* Membentuk sebuah MatrixKulkas "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    ROW_EFFK(*m) = nRows;
    COL_EFFK(*m) = nCols;

    infotype dummy;
    makeDummyInfoType(&dummy);

    for(int i=0;i<ROW_EFFK(*m);i++){
        for(int j=0;j<COL_EFFK(*m);j++){
            ELMTK(*m, i, j) = dummy;
        }
    }
}

/* *** Selektor "Dunia MatrixKulkas" *** */
boolean isMatrixKulkasIdxValid(int i, int j)
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
{
    return (i>=0 && i<ROW_CAP_K && j>=0 && j<COL_CAP_K);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRowKulkas(MatrixKulkas m)
/* Mengirimkan Index baris terbesar m */
{
    return (IdxType) ROW_EFFK(m)-1;
}
IdxType getLastIdxColKulkas(MatrixKulkas m)
/* Mengirimkan Index kolom terbesar m */
{
    return (IdxType) COL_EFFK(m)-1;
}
boolean isIdxEffKulkas(MatrixKulkas m, IdxType i, IdxType j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
    return (i>=0 && i<ROW_EFFK(m) && j>=0 && j<COL_EFFK(m));
}

/* ********** Assignment  MatrixKulkas ********** */
void copyMatrixKulkas(MatrixKulkas mIn, MatrixKulkas *mOut)
/* Melakukan assignment mOut <- mIn */
{
    createMatrixKulkas(ROW_EFFK(mIn), COL_EFFK(mIn), mOut);
    for(int i=0;i<ROW_EFFK(mIn);i++){
        for(int j=0;j<COL_EFFK(mIn);j++){
            ELMTK(*mOut,i,j) = ELMTK(mIn,i,j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */

void displayMatrixKulkas(MatrixKulkas m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    for(int i=0;i<ROW_EFFK(m);i++){
        for(int j=0;j<COL_EFFK(m);j++){
            if(j>0){
                printf(" ");
            }
            printf("%d", ID(Info(ELMTK(m,i,j))));
        }
        printf("\n");
    }
}


/* ********** Operasi lain ********** */
int countElmtKulkas(MatrixKulkas m)
/* Mengirimkan banyaknya elemen m */
{
    return (ROW_EFFK(m)*COL_EFFK(m));
}

int countElmtDummy(MatrixKulkas m) {
/* Menghitung banyaknya elemen dummy di kulkas */

    int ctr = 0;
    infotype var;

    makeDummyInfoType(&var);
    for(int i=0;i<ROW_EFFK(m);i++){
        for(int j=0;j<COL_EFFK(m);j++){
            infotype temp = ELMTK(m, i, j);
            if ((ID(Info(temp)) == ID(Info(var))) && (NAME(Info(temp)) == NAME(Info(var))) && (LOC(Info(temp)) == LOC(Info(var))) && (TIMEToMenit(EXP(Info(temp))) == TIMEToMenit(EXP(Info(var)))) && (TIMEToMenit(DELIVERY(Info(temp))) == TIMEToMenit(DELIVERY(Info(var))))) {
                ctr++;
            }
        }
    }
    return ctr;
}

boolean isFullKulkas(MatrixKulkas m) {
/* Mengirim true jika kulkas penuh, false jika tidak */

    return (countElmtDummy(m) == 0);
}

/* ********** KELOMPOK TEST TERHADAP MatrixKulkas ********** */
boolean isSquareKulkas(MatrixKulkas m)
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
{
    return (ROW_EFFK(m) == COL_EFFK(m));
}
