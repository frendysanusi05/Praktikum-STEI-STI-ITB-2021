/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 19 September 2022
Topik praktikum: Pasca Praktikum 3 - ADT, Pointer, Array Dinamik
Deskripsi: Implementasi jumlahkonsonanvokal.h
*/
#include "jumlahkonsonanvokal.h"

isAlphabet (char c) {
// Mengembalikan true jika c adalah alfabet
    // KAMUS LOKAL
    // ALGORITMA
    return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

isVokal (char c) {
// Mengembalikan true jika c adalah huruf vokal
    // KAMUS LOKAL
    // ALGORITMA
    return (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o' || c == 'A' || c == 'E' || c == 'I' || c == 'U' || c == 'O');
}

// Parameter pertama merupakan kalimat
// Parameter kedua merupakan jumlah huruf konsonan
// Parameter ketiga merupakan jumlah huruf vokal
void jumlahKonsonanVokal(char* c, int* k, int* v) {
    // KAMUS LOKAL
    int i = 0;
    // ALGORITMA
    while (c[i] != '\0') {
        if (isAlphabet(c[i])) {
            if (isVokal(c[i])) {
                *v += 1;
            } else {
                *k += 1;
            }
        }
        i++;
    }
}