/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 23 September 2022
Topik praktikum: Pasca Praktikum 3 - ADT, Pointer, Array Dinamik
Deskripsi: Implementasi arraydin.h
*/

#include "arraydin.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin() {
    // KAMUS LOKAL
    ArrayDin array;
    // ALGORITMA
    array.A = (ElType*) malloc (InitialSize *sizeof(ElType));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array) {
    // KAMUS LOKAL
    // ALGORITMA
    free(array->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array) {
    // KAMUS LOKAL
    // ALGORITMA
    return (array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array) {
    return (array.Neff);
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i) {
    // KAMUS LOKAL
    // ALGORITMA
    return (array.A[i]);
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array) {
    // KAMUS LOKAL
    // ALGORITMA
    return (array.Capacity);
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i) {
    // KAMUS LOKAL
    int j;
    ElType *temp;
    // ALGORITMA
    if (Length(*array) == GetCapacity(*array)) {
        temp = (ElType*) malloc ((GetCapacity(*array) + InitialSize) *sizeof(ElType));

        for (j = 0; j < Length(*array); j++) {
            temp[j] = array->A[j];
        }
        DeallocateArrayDin(array);
        array->Capacity = GetCapacity(*array) + InitialSize;
        array->A = temp;
    }

    for (j = Length(*array); j > i; j--) {
        array->A[j] = array->A[j-1];
    }
    array->Neff++;
    array->A[j] = el;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDin *array, ElType el) {
    // KAMUS LOKAL
    // ALGORITMA
    InsertAt(array, el, (array->Neff));
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDin *array, ElType el) {
    // KAMUS LOKAL
    // ALGORITMA
    InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i) {
    // KAMUS LOKAL
    int j;
    // ALGORITMA
    for (j = i; j < Length(*array) - 1; j++) {
        array->A[j] = array->A[j+1];
    }
    array->Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *array) {
    // KAMUS LOKAL
    // ALGORITMA
    DeleteAt(array, (array->Neff));
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array) {
    // KAMUS LOKAL
    // ALGORITMA
    DeleteAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array) {
    // KAMUS LOKAL
    int j;
    // ALGORITMA
    printf("[");
    for (j = 0; j < Length(array); j++) {
        if (j == array.Neff - 1) {
            printf("%d", array.A[j]);
        } else {
            printf("%d, ", array.A[j]);
        }
    }
    printf("]\n");
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array) {
    // KAMUS LOKAL
    int j, temp;
    // ALGORITMA
    for (j = 0; j < (Length(*array) - 1)/2; j++) {
        temp = array->A[j];
        array->A[j] = array->A[Length(*array) - 1 - j];
        array->A[Length(*array) - 1 - j] = temp;
    }
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array) {
    // KAMUS LOKAL
    // ALGORITMA
    return array;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, ElType el) {
    // KAMUS LOKAL
    int j = 0;
    // ALGORITMA
    while (j < Length(array)) {
        if (array.A[j] == el) {
           return j;
        } else {
            j++;
        }
    }
    return -1;
}