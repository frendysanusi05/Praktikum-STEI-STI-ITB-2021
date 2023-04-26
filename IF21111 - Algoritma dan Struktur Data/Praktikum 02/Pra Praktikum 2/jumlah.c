/*
NIM: 18221041
Nama: Frendy Sanusi
Tanggal: 11 September 2022
Topik praktikum: Pengenalan C
Deskripsi: Menjumlahkan semua digit bilangan dalam integer tersebut
*/

// File jumlah.c
#include <stdio.h>

int main() {
    // KAMUS
    int n, sum = 0;
    // ALGORITMA
    scanf("%d", &n);
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    printf("%d\n", sum);
    return 0;
}