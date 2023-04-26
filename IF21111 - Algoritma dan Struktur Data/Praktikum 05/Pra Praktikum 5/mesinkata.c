/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 2 Oktober 2022
Topik praktikum: Pra Praktikum 5 - Mesin Karakter
Deskripsi: Implementasi mesinkata.h
*/

#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    // KAMUS LOKAL
    // ALGORITMA
    while (currentChar == BLANK) {
        ADV();
    }
}

void STARTWORD() {
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    // KAMUS LOKAL
    // ALGORITMA
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    // KAMUS LOKAL
    // ALGORITMA
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
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
    // KAMUS LOKAL
    int i = 0;
    // ALGORITMA
    while ((currentChar != MARK) && (currentChar != BLANK) && (i < NMax)) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}