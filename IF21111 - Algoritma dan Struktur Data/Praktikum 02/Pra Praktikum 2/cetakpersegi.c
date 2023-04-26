/*
NIM: 18221041
Nama: Frendy Sanusi
Tanggal: 11 September 2022
Topik praktikum: Pengenalan C
Deskripsi: Mencetak sebuah persegi dengan panjang sisi 2n-1 dan dibentuk dengan pola O dan X secara selang-seling
*/

// File cetakpersegi.c
#include <stdio.h>

int main() {
    // KAMUS
    int n, i, j;
    // ALGORITMA
    scanf("%d", &n);
    for (i = 1; i <= (2*n - 1); i++) {
        for (j = 1; j <= (2*n - 1); j++) {
            if (i % 2 != 0) {
                if (j % 2 != 0) {
                    printf("O");
                } else {
                    printf("X");
                }
            } else {
                if (j % 2 != 0) {
                    printf("X");
                } else {
                    printf("O");
                }
            }
        }
        printf("\n");
    }
    return 0;
}