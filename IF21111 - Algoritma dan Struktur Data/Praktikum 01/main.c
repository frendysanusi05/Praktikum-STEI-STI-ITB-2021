/*
NIM : 18221041
Nama : Frendy Sanusi
Tanggal : 2 September 2022
Topik praktikum : Pengenalan C
Deskripsi : Menerima masukan detik dan mengeluarkan keluaran dalam format jam, menit, dan detik
*/

// File main.c
#include <stdio.h>

int main() {
    // KAMUS
    int t, h, m, s, sisa;
    // ALGORITMA
    scanf("%d", &t);
    h = t / 3600;
    sisa = t % 3600;
    m = sisa / 60;
    s = sisa % 60;
    printf("%d detik = %d jam %d menit %d detik\n", t,h,m,s);
    return 0;
}