/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 24 September 2022
Topik praktikum: Pasca Praktikum 2 - Pengenalan C
Deskripsi: 
*/

#include <stdio.h>

int main() {
    // KAMUS
    int n, countAll = 0, countLulus = 0;
    double avg, sum = 0;
    char indeks;
    // ALGORITMA
    scanf("%d", &n);
    while (n != -999) {
        if ((n >= 0) && (n <= 4)) {
            sum += n;
            countAll += 1;
            if (n >= 3) {
                countLulus += 1;
            }
        }
        scanf("%d", &n);
    }
    if (countAll == 0) {
        printf("Tidak ada data\n");
    } else {
        avg = sum / countAll;
        if (avg == 4.00) {
            indeks = 'A';
        } else if (avg >= 3.00 && avg < 4.00) {
            indeks = 'B';
        } else if (avg >= 2.00 && avg < 3.00) {
            indeks = 'C';
        } else if (avg >= 1.00 && avg < 2.00) {
            indeks = 'D';
        } else {
            indeks = 'E';
        }
        printf("Jumlah mahasiswa yang lulus = %d\n", countLulus);
        printf("Nilai rata-rata = %.2f\n", avg);
        printf("Indeks akhir kelas = %c\n", indeks);
    }
    return 0;
}