/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

// #ifndef __MESINKATA_H__
// #define __MESINKATA_H__

// #include "../../include/boolean.h"
// #include "charmachine.h"

// #define NMax 100
// #define BLANK ' '

// typedef struct {
//    char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
//    int Length;
// } Word;

// typedef struct {
//    Word TabWords[NMax];
//    int Length;
// } ListWord;

// /* State Mesin Word */
// extern boolean EndWord;
// extern Word currentWord;

// void IgnoreBlanks();
// /* Mengabaikan satu atau beberapa BLANK
//    I.S. : currentChar sembarang
//    F.S. : currentChar ≠ BLANK atau currentChar = MARK */

// void STARTWORD();
// /* I.S. : currentChar sembarang
//    F.S. : EndWord = true, dan currentChar = MARK;
//           atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
//           currentChar karakter pertama sesudah karakter terakhir kata */

// void STARTWORDFILE(char *dir);
// /* Sama seperti STARTWORD hanya dalam input File*/

// void ADVWORD();
// /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
//    F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
//           currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
//           Jika currentChar = MARK, EndWord = true.
//    Proses : Akuisisi kata menggunakan procedure SalinWord */

// void CopyWord();
// /* Mengakuisisi kata, menyimpan dalam currentWord
//    I.S. : currentChar adalah karakter pertama dari kata
//    F.S. : currentWord berisi kata yang sudah diakuisisi;
//           currentChar = BLANK atau currentChar = MARK;
//           currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
//           Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

// void ADVNewline();
// /* ADV untuk membaca pita dalam line baru */

// void displayWord(Word w);
// /* Display currentWord ke console */

// int wordToInt(Word currentWord);
// /* Mengubah currentWord ke integer 
//    I.S. : currentWord adalah word berupa angka
//    F.S. : mengembalikan integer dari currentWord*/

// void createListWord(ListWord *L);
// /* Membuat list of words
//    I.S. : L sembarang
//    F.S. : Inisiasi ListWord dengan length = 0*/

// ListWord readLine();
// /* Membaca line masukan user dari console*/

// ListWord readLineFile();
// /* Membaca line masukan user dari file*/

// boolean isWordEq(Word w1, Word w2);
// /* Menghasilkan true jika word sama */

// void copyWord(Word w1, Word *w2);
// /* Copy Word w1 ke Word w2 */

// Word concatWord(Word w1, Word w2);
// /* Concat Word w1 dan Word w2 menjadi Word baru */

// char *ListWordToString(ListWord L);

// char *wordToString(Word w);

// #endif