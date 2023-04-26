/*
NIM: 18221041
Nama: Frendy Sanusi
Tanggal: 11 September 2022
Topik: Pengenalan C
Deskripsi: Menentukan apakah bilangan tersebut merupakan bilangan subset genap
*/

// File subset.c
#include <stdio.h>

int main() {
    // KAMUS
    long long bil;
    // ALGORITMA
    scanf("%lld", &bil);
    if (bil > 2 && bil % 2 == 0) {
        printf("Ya\n");
    } else {
        printf("Tidak\n");
    }
    return 0;
}