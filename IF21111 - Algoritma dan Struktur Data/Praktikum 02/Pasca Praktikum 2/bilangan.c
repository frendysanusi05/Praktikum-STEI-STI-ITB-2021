/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 24 September 2022
Topik praktikum: Pasca Praktikum 2 - Pengenalan C
Deskripsi: Menghitung jumlah angka cantik dalam rentang 1 sampai M
*/

#include <stdio.h>

int main() {
    // KAMUS
    int N, M, i, bil = 1, sum = 0, found = 0, sisa;
    // ALGORITMA
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &M);
        while (bil <= M) {
            if (bil % 7 == 0) {
                sum += bil;
            } else {
                sisa = bil;
                while ((sisa > 0) && (found == 0)) {
                    if (sisa % 10 == 7) {
                        found = 1;
                    }
                    sisa /= 10;
                }
                if (found == 1) {
                    sum += bil;
                    found = 0;
                }
            }
            bil++;
        }
        printf("%d\n", sum);
        sum = 0;
        bil = 1;
    }
    return 0;
}