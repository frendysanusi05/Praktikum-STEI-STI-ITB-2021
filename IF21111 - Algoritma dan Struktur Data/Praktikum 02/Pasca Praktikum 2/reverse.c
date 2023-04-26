/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 24 September 2022
Topik praktikum: Pasca Praktikum 2 - Pengenalan C
Deskripsi: Memberikan output integer tersebut dengan tiap digitnya sudah dibalik
*/

#include <stdio.h>

int main() {
    // KAMUS
    long long n, reverse = 0;
    // ALGORITMA
    scanf("%lld", &n);
    while (n > 0) {
        reverse = reverse*10 + n % 10;
        n /= 10;
    }
    printf("%lld\n", reverse);
    return 0;
}