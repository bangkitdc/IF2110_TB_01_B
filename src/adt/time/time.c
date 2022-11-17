#include <stdio.h>
#include "./time.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int D, int H, int M)
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
{
    if(H>=0 && H<=23 && M>=0 && M<=59 && D>=0){
      return true;
    }else{
      return false;
    }
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int DD, int HH, int MM)
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, SS valid untuk membentuk TIME */
{
    Day(*T) = DD;
    Hour(*T) = HH;
    Minute(*T) = MM;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
   
void TulisTIME (TIME T)
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
{
   printf("%d:%d:%d", Day(T), Hour(T), Minute(T));
}

void TulisTIME2 (TIME T)
{
   if(T.DD > 0){
      printf("%d hari", T.DD);
   }
   if(T.HH > 0){
      if (T.DD > 0) {
         printf(" ");
      }
      printf("%d jam", T.HH);
   }
   if(T.MM > 0){
      if (T.HH > 0) {
         printf(" ");
      }
      printf("%d menit", T.MM);
   }

   if (T.DD == 0 && T.HH == 0 && T.MM == 0) {
      printf("0 menit");
   }
}

void TulisTIME3 (TIME T) {
   printf("Waktu: %02d.%02d\n", Hour(T), Minute(T));
}

void TulisTIME4 (TIME T) {
   boolean hari = false;
   boolean jam = false;
   boolean menit = false;
   if(T.DD > 0){
      printf("%-2d %-5s", T.DD, "hari");
      hari = true;
   }
   if(T.HH > 0){
      if (hari) {
         printf(" ");
      }
      printf("%-2d %-5s", T.HH, "jam");
      jam = true;
   }
   if(T.MM > 0){
      if (jam) {
         printf(" ");
      }
      printf("%-2d %-5s", T.MM, "menit");
      menit = true;
   }
   if (jam && !hari && !menit || hari && !jam && !menit || menit && !hari && !jam) {
      printf("\t");
   }
}

void TulisTIME5 (TIME T) {
   boolean hari = false;
   boolean jam = false;
   boolean menit = false;
   printf("(");
   if(T.DD > 0){
      printf("%-2d %-5s", T.DD, "hari");
      hari = true;
   }
   if(T.HH > 0){
      if (hari) {
         printf(" ");
      }
      printf("%-2d %-5s", T.HH, "jam");
      jam = true;
   }
   if(T.MM > 0){
      if (jam) {
         printf(" ");
      }
      printf("%-2d %-5s", T.MM, "menit");
      menit = true;
   }
   printf(")");
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToMenit (TIME T)
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah menit */
{
   return 1440*Day(T) + 60*Hour(T) + Minute(T);
}

TIME MenitToTIME (long N)
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
{
   TIME waktu;
   int h,j,m;
   h = N/1440;
   N %= 1440;
   j = N/60;
   N %= 60;
   m = N; 
   CreateTime(&waktu, h, j, m);
   return waktu;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1=T2, false jika tidak */
{
   if(Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2) && Day(T1) == Day(T2)){
      return true;
   }else{
      return false;
   }
}
boolean TNEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1 tidak sama dengan T2 */
{
   if(Hour(T1) != Hour(T2) || Minute(T1) != Minute(T2) || Day(T1) != Day(T2)){
      return true;
   }else{
      return false;
   }
}
boolean TLT (TIME T1, TIME T2)
/* Mengirimkan true jika T1<T2, false jika tidak */
{
   if(TIMEToMenit(T1) < TIMEToMenit(T2)){
      return true;
   }else{
      return false;
   }
}
boolean TGT (TIME T1, TIME T2)
/* Mengirimkan true jika T1>T2, false jika tidak */
{
   if(TIMEToMenit(T1) > TIMEToMenit(T2)){
      return true;
   }else{
      return false;
   }
}
/* *** Operator aritmatika TIME *** */
TIME NextMenit (TIME T)
{
   long menit;
   menit = (TIMEToMenit(T) + 1);
   return MenitToTIME(menit);
}
TIME NextNMenit (TIME T, int N)
{
   long menit;
   menit = (TIMEToMenit(T) + N);
   return MenitToTIME(menit);
}
TIME PrevMenit (TIME T)
{
   long menit;
   menit = TIMEToMenit(T) - 1;
   return MenitToTIME(menit);
}

TIME PrevNMenit (TIME T, int N)
{
   long detik;
   detik = TIMEToMenit(T) - N;
   return MenitToTIME(detik);
}
/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh)
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
{
   long durasi;
   if(TLT(TAw, TAkh)){
      durasi = TIMEToMenit(TAkh) - TIMEToMenit(TAw);
   }else if(TEQ(TAw, TAkh)){
      durasi = 0;
   }else{
      durasi = TIMEToMenit(TAw) + TIMEToMenit(TAkh);
   }
   return durasi;
}
