/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 16 September 2022
Topik praktikum: Pra Praktikum 3 - ADT, Pointer, Array Dinamik
Deskripsi: Implementasi arraydin.h
*/

#include "arraydin.h"
#include <stdlib.h>

// Konstruktor
ArrayDin MakeArrayDin() {
    /*
    * I.S. sembarang
    * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
    */
    // KAMUS LOKAL
    ArrayDin array;
    // ALGORITMA
    array.A = (ElType*) malloc (InitialSize* sizeof(ElType));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

// Destruktor
void DeallocateArrayDin(ArrayDin *array) {
    /*
    * I.S. ArrayDin terdefinisi
    * F.S. array->A terdealokasi
    */
    // KAMUS LOKAL
    // ALGORITMA
    return free(array->A);
    array->Capacity = 0;
    array->Neff = 0;
}

boolean IsEmpty(ArrayDin array) {
    /*
    * Fungsi untuk mengetahui apakah suatu array kosong.
    * Prekondisi: array terdefinisi
    */
    // KAMUS LOKAL
    // ALGORITMA
    return (array.Neff == 0);
}

int Length(ArrayDin array) {
    /*
    * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
    * Prekondisi: array terdefinisi
    */
    // KAMUS LOKAL
    // ALGORITMA
    return array.Neff;
}

ElType Get(ArrayDin array, IdxType i) {
    /**
    * Mengembalikan elemen array L yang ke-I (indeks lojik).
    * Prekondisi: array tidak kosong, i di antara 0..Length(array).
    */
    // KAMUS LOKAL
    // ALGORITMA
    return array.A[i];
}

int GetCapacity(ArrayDin array) {
    /**
    * Fungsi untuk mendapatkan kapasitas yang tersedia.
    * Prekondisi: array terdefinisi
    */
    // KAMUS LOKAL
    // ALGORITMA
    return array.Capacity;
}

void InsertAt(ArrayDin *array, ElType el, IdxType i) {
    /**
    * Fungsi untuk menambahkan elemen baru di index ke-i
    * Prekondisi: array terdefinisi, i di antara 0..Length(array).
    */
    // KAMUS LOKAL
    int j;
    // ALGORITMA
    array->Neff++;
    for (j = Length(*array); j > i; j--) {
        array->A[j] = array->A[j - 1];
    }
    array->A[j] = el;
}

void DeleteAt(ArrayDin *array, IdxType i) {
    /**
    * Fungsi untuk menghapus elemen di index ke-i ArrayDin
    * Prekondisi: array terdefinisi, i di antara 0..Length(array).
    */
    // KAMUS LOKAL
    int j;
    // ALGORITMA
    for (j = i; j < Length(*array); j++) {
        array->A[j] = array->A[j + 1];
    }
    array->Neff--;
}