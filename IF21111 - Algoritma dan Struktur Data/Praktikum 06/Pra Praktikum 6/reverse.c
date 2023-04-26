/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 15 Oktober 2022
Topik praktikum: Queue - Pra Praktikum 6
Deskripsi: Implementasi reverse.h
*/

#include "reverse.h"

void transferReverse(Queue* q1, Queue* q2) {
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik
    // KAMUS LOKAL
    ElType temp;
    int i, currentHead, currentTail;
    // ALGORITMA
    for (i = Length(*q1); i > 0; i--) {
        Push(q2, Pop(q1));
    }

    currentHead = 0;
    currentTail = Length(*q2) - 1;

    while (currentHead < currentTail) {
        temp = q2->Tab[currentHead];
        q2->Tab[currentHead] = q2->Tab[currentTail];
        q2->Tab[currentTail] = temp;

        currentHead++;
        currentTail--;
    }
}