/* File: wordmachine.c */
/* Implementasi Mesin Kata */

#include <stdlib.h>
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
      if (currentWord.Length < NMax1) {
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
   for (i = 0; i < currentWord.Length; i++) {
      if (currentWord.TabWord[i] >= '0' && currentWord.TabWord[i] <= '9') {
         val = val * 10 + (currentWord.TabWord[i] - '0');
      } else {
         return -999;
      }
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

boolean isWordEq(Word w1, Word w2) {
   if (w1.Length != w2.Length) {
      return false;
   } else {
      int i = 0;
      boolean isEq = true;

      while (i < w1.Length && isEq) {
         if (w1.TabWord[i] != w2.TabWord[i]) {
            isEq = false;
         }
         i ++;
      }

      return isEq;
   }
}

void copyWord(Word w1, Word *w2) {
   int i;

   w2->Length = w1.Length;
   for (i = 0; i < w1.Length; i ++) {
      w2->TabWord[i] = w1.TabWord[i];
   }
}

Word concatWord(Word w1, Word w2) {
   Word res;
   res.Length = w1.Length + w2.Length;
   int i;
   for (i = 0; i < w1.Length; i ++) {
      res.TabWord[i] = w1.TabWord[i];
   }
   for (i = 0; i < w2.Length; i ++) {
      res.TabWord[i + w1.Length] = w2.TabWord[i];
   }
   return res;
}

char *wordToString(Word w) {
   char *buffer = (char *)malloc(w.Length * sizeof(char));
   int i;
   for (i = 0; i < w.Length; i ++) {
      buffer[i] = (char)w.TabWord[i];
   }
   buffer[w.Length] = '\0';
   return buffer;
}

char *ListWordToString(ListWord L) {
   int len = 0;
   int i, j;
   for (i = 0; i < L.Length; i ++) {
      for (j = 0; j < L.TabWords[i].Length; j ++) {
         len ++;
      }
   }
   len += L.Length - 1;
   char *res = (char *) malloc(len * sizeof(char));
   int counter = 0;
   for (i = 0; i < L.Length; i ++) {
      for (j = 0; j < L.TabWords[i].Length; j ++) {
         res[counter] = L.TabWords[i].TabWord[j];
         counter ++;
      }
      if (i != L.Length - 1) {
         res[counter] = ' ';
         counter ++;
      }
   }
   res[counter] = '\0';
   return res;
}
