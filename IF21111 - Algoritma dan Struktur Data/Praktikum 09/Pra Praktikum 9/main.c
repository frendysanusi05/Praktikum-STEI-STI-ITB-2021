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
    List L1, L2;
    boolean valid = true;
    int nilai;
    // ALGORITMA
    CreateEmpty(&L1); CreateEmpty(&L2);
    while (valid) {
        scanf("%d", &nilai);
        if (nilai < 0 || nilai > 100) valid = false;
        else {
            InsVFirst(&L1, nilai);
            InsVFirst(&L2, nilai);
        }
    }

    if (IsEmpty(L1)) printf("Daftar nilai kosong\n");
    else {
        printf("%d\n%d\n%d\n%.2f\n", NbElmt(L1), Max(L1), Min(L1), Average(L1));  
        InversList(&L2);
        PrintInfo(L2);
        printf("\n");
        PrintInfo(L1);
        printf("\n");
    }

    return 0;
}