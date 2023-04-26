/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 24 September 2022
Topik praktikum: Pasca Praktikum 2 - Pengenalan C
Deskripsi: Mencetak sebuah persegi berdasarkan masukkan n, dimana panjang dari sisi persegi adalah 2n-1 dan dibentuk dengan pola O dan X secara selang-seling.
*/

#include <stdio.h>

int square(int num) {
    // KAMUS LOKAL
    // ALGORITMA
    return num * num;
}

int main() {
    // KAMUS
    int n, i;
    // ALGORITMA
    scanf("%d", &n);
    for (i = 1; i <= square(2*n-1); i++) {
        if (i % 2 == 0) {
            printf("X");
        } else {
            printf("O");
        }
        if (i % (2*n-1) == 0) {
            printf("\n");
        }
    }
    return 0;
}