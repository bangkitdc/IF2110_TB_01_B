/* File: wordmachine.c */
/* Implementasi Mesin Kata */

#include "../../utility/boolean.h"
#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

/* State Mesin Word */
boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

   /* ALGORITMA */
   while (currentChar == BLANK) {
      ADV();
   }
}

void STARTWORD(){
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

   /* ALGORITMA */
   START();
   IgnoreBlanks();
   if (currentChar == MARK) {
      EndWord = true;
   } else {
      EndWord = false;
      CopyWord();
   }
}

void STARTWORDFILE(char *dir) {
   /* Sama seperti STARTWORD hanya dalam input File */

   /* ALGORITMA */
   STARTFILE(dir);
   IgnoreBlanks();
   if (currentChar == MARK) {
      EndWord = true;
   } else {
      EndWord = false;
      CopyWord();
   }
}

void ADVWORD(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

   /* ALGORITMA */
   IgnoreBlanks();
   if (currentChar == MARK) {
      EndWord = true;
   } else {
      CopyWord();
      IgnoreBlanks();
   }
}

void CopyWord(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

   /* ALGORITMA */
   currentWord.Length = 0;
   while (currentChar != BLANK && currentChar != MARK) {
      if (currentWord.Length < NMax) {
         currentWord.TabWord[currentWord.Length] = currentChar;
         currentWord.Length += 1;
         ADV();
      } else {
         break;
      }
   }
}

void ADVNewline() {
   ADVWORD();
   if (EndWord) {
      if (currentChar == MARK) {
         EndWord = false;
         ADV();
         CopyWord();
         if (currentWord.Length == 0)
         {
            closeChar();
            EndWord = true;
         }
      }
   } 
}

void displayWord(Word w) {
   int i;
   for (i = 0; i < w.Length; i ++) {
      printf("%c", w.TabWord[i]);
   }
}

int wordToInt(Word currentWord) {
   int i;
   int val = 0;
   for (i = 0; i < currentWord.Length; i++)
   {
      val = val * 10 + (currentWord.TabWord[i] - '0');
   }
   return val;
}

void createListWord(ListWord *L) {
   (*L).Length = 0;
}

ListWord readLineFile() {
   ListWord L;
   createListWord(&L);
   while (!EndWord) {
      L.TabWords[L.Length] = currentWord;
      L.Length += 1;
      ADVWORD();
   }
   return L;
}

ListWord readLine() {
   ListWord L;
   createListWord(&L);
   STARTWORD();
   while (!EndWord) {
      L.TabWords[L.Length] = currentWord;
      L.Length += 1;
      ADVWORD();
   }
   return L;
}