/*
NIM: 18221041
Nama: Frendy Sanusi
Tanggal: 11 September 2022
Topik: Pengenalan C
Deskripsi: Menentukan apakah bilangan masukan adalah strong number atau buka
*/

// File strongnumber.c
#include <stdio.h>

// Fungsi factorial
long long factorial(long long n) {
    // KAMUS LOKAL
    long long sum = 0, temp = 1;
    int i;
    // ALGORITMA
    if (n == 0) {
        return 1;
    } else {
        while (n != 0) {
            i = n % 10;
            n /= 10;
            while (i > 0) {
                temp *= i;
                i--;
            }
            sum += temp;
            temp = 1;
        }
        return sum;
    }
}

int main() {
    // KAMUS
    long long bil;
    // ALGORITMA
    scanf("%lld", &bil);
    if (bil == factorial(bil)) {
        printf("Y\n");
    } else {
        printf("N\n");
    }
    return 0;
}