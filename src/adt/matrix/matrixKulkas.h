/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MATRIXKULKAS_H
#define MATRIXKULKAS_H

#include "../../include/boolean.h"
#include "../queue/Prioqueue.h"

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100

typedef int IdxType; /* Index baris, kolom */
typedef infotype ElType;
typedef struct
{
   ElType mem[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MatrixKulkas;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrixKulkas(int nRows, int nCols, MatrixKulkas *m);
/* Membentuk sebuah MatrixKulkas "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROW_EFFK(M) (M).rowEff
#define COL_EFFK(M) (M).colEff
#define ELMTK(M, i, j) (M).mem[(i)][(j)]

/* *** Selektor "Dunia MatrixKulkas" *** */
boolean isMatrixKulkasIdxValid(int i, int j);
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRowKulkas(MatrixKulkas m);
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxColKulkas(MatrixKulkas m);
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEffKulkas(MatrixKulkas m, IdxType i, IdxType j);
/* Mengirimkan true jika i, j adalah Index efektif bagi m */

/* ********** Assignment  MatrixKulkas ********** */
void copyMatrixKulkas(MatrixKulkas mIn, MatrixKulkas *mOut);
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void displayMatrixKulkas(MatrixKulkas m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** Operasi lain ********** */
int countElmtKulkas(MatrixKulkas m);
/* Mengirimkan banyaknya elemen m */

boolean isFullKulkas(MatrixKulkas m);
/* Mengirim true jika kulkas penuh, false jika tidak */

/* ********** KELOMPOK TEST TERHADAP MatrixKulkas ********** */
boolean isSquareKulkas(MatrixKulkas m);
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */

#endif