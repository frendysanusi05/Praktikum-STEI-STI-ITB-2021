/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 28 September 2022
Topik praktikum: Pasca Praktikum 4 - Array dan ADT List
Deskripsi: Implementasi fibonacci.h
*/

#include "fibonacci.h"

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci ke argumen result
// Contoh:
// n = 5
// Nilai argumen result = 8
void fibonacci1(int n, int *result) {
    // KAMUS LOKAL
    // ALGORITMA
    *result = fibonacci2(n);
}

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci
int fibonacci2(int n) {
    // KAMUS LOKAL
    int fib;
    // ALGORITMA
    if (n == 0 || n == 1) {
        fib = 1;
    } else {
        fib = fibonacci2(n - 1) + fibonacci2(n - 2);
    }
    return fib;
}

// Menerima argument sebuah integer n
// Output adalah argumen result yang bertipe pointer int digunakan sebagai array
// Tuliskan semua nilai deret fibonacci dari 0 - n ke argumen result
// n = 5
// result = [1, 1, 2, 3, 5, 8]
void fibonacci3(int n, int *result) {
    // KAMUS LOKAL
    // ALGORITMA
    for (int i = 0; i <= n; i++) {
        *(result+i) = fibonacci2(i);
    }
}