/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 22 Oktober 2022
Topik praktikum: Pasca Praktikum 5 - Mesin Karakter
Deskripsi: Implementasi mesinkarakter.h
*/
#include "mesinkarakter.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
   // KAMUS LOKAL
   // ALGORITMA
   pita = stdin;
   ADV();
}

void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
   // KAMUS LOKAL
   // ALGORITMA
   retval = fscanf(pita, "%c", &currentChar);
   if (IsEOP()) {
      fclose(pita);
   }
}

char GetCC() {
/* Mengirimkan currentChar */
   // KAMUS LOKAL
   // ALGORITMA
   return currentChar;
}

boolean IsEOP() {
/* Mengirimkan true jika currentChar = MARK */
   // KAMUS LOKAL
   // ALGORITMA
   if (currentChar == MARK) {
      return true;
   } else {
      return false;
   }
}