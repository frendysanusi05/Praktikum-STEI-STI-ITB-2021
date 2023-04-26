/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 2 Oktober 2022
Topik praktikum: Pra Praktikum 5 - Mesin Karakter
Deskripsi: Menghitung jumlah kemunculan karakter yang diperoleh dari stdin
*/

#include "mesinkarakter.h"
#include <stdio.h>

int hitungkarakter(char karakter) {
    // KAMUS LOKAL
    int cnt = 0;
    // ALGORITMA
    START();
    while (!IsEOP()) {
        if (GetCC() == karakter) {
            cnt++;
        }
        ADV();
    }
    return cnt;
}