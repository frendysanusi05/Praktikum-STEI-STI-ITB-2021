/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 16 September 2022
Topik praktikum: Pra Praktikum 3 - ADT, Pointer, Array Dinamik
Deskripsi: Implementasi point.h
*/

#include <stdio.h>
#include "panjangstring.h"

int panjangString(char* c) {
    // KAMUS LOKAL
    int count = 0;
    // ALGORITMA
    while (*c != '\0') {
        count++;
        c++;
    }
    return count;
}