/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"
#include "stdlib.h"
#include "string.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK) {
        ADV(); 
    }
}

void STARTWORD() {
/* I.S. : currentChar sembarang
   F.S. : endWord = true, dan currentChar = MARK;
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        endWord = true;
    } else {
        endWord = false;
        CopyWord();
    }
}

void ADVWORD() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanks();
    if (currentChar == MARK) {
        endWord = true;
    } else {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord() {
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    while (currentChar != MARK && currentChar != BLANK) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }

    if (i > NMax) {
        currentWord.Length = NMax;
    } else {
        currentWord.Length = i;
    }
    currentWord.TabWord[i] = '\0';
}

