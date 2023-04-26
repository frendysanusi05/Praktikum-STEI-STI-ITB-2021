/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 24 September 2022
Topik praktikum: Pasca Praktikum 2 - Pengenalan C
Deskripsi: Menjumlahkan setiap digit dari integer tersebut
*/

#include <stdio.h>

int main() {
    // KAMUS
    long long n, sum = 0;
    // ALGORITMA
    scanf("%lld", &n);
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    printf("%lld\n", sum);
    return 0;
}