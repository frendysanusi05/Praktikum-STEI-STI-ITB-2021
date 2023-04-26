/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 5 November 2022
Topik praktikum: Struktur Berkait
Deskripsi: Mengelola statistik daftar nilai sebuah mata kuliah (asumsi nilai selalu 0..100)
*/

#include <stdio.h>
#include "listlinier.h"

int main() {
    // KAMUS LOKAL
    List L1, L2, L3;
    boolean negative = false;
    int nilai, X;
    address p, prec;
    // ALGORITMA
    CreateEmpty(&L1); CreateEmpty(&L2); CreateEmpty(&L3);
    while (!negative) {
        scanf("%d", &nilai);
        if (nilai < 0) negative = true;
        else {
            InsVLast(&L1, nilai);
        }
    }
    // negative = false;
    // while (!negative) {
    //     scanf("%d", &nilai);
    //     if (nilai < 0) negative = true;
    //     else {
    //         InsVLast(&L2, nilai);
    //     }
    // }

    // prec = Search(L1, 2);
    // p = Alokasi(7);
    // printf("%d\n", Info(Search(L1, 1)));
    // DelVFirst(&L1, &X);
    // Konkat1(&L1, &L2, &L3);
    // PrintInfo(L3);
    // printf("\n");
    // PrintInfo(L2);
    // printf("\n");
    InversList(&L1);
    PrintInfo(L1);

    return 0;
}