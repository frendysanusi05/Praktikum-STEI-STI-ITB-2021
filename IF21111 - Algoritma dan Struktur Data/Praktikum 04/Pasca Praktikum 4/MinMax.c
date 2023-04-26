/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 28 September 2022
Topik praktikum: Pasca Praktikum 4 - Array dan ADT List
Deskripsi: Implementasi MinMax.h
*/

#include "MinMax.h"

List MinMax(List L) {
    // KAMUS LOKAL
    int max, min;
    int indexmax = 0, indexmin = 0;
    List MinMaxL = L;
    // ALGORITMA
    for (int i = 1; L.A[i] != Mark; i++) {
        if (L.A[i] > L.A[indexmax]) {
            indexmax = i;
        }
        if (L.A[i] < L.A[indexmin]) {
            indexmin = i;
        }
    }
    max = L.A[indexmax];
    min = L.A[indexmin];

    DeleteAt(&MinMaxL, indexmax);

    if (indexmax < indexmin) {
        DeleteAt(&MinMaxL, indexmin-1);
    } else {
        DeleteAt(&MinMaxL, indexmin);
    }
    InsertLast(&MinMaxL, min);
    InsertLast(&MinMaxL, max);
    return MinMaxL;
}