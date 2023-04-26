/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 22 Oktober 2022
Topik praktikum: Queue - Pasca Praktikum 6
Deskripsi: Impelementasi copyqueue.h
*/

#include "copyqueue.h"

void copyQueue(Queue *queueInput, Queue *queueOutput) {
/* Proses: Menyalin isi dari queueInput ke queueOutput */
/* I.S. queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
/* F.S. queueOutput memiliki isi queue yang sama */
/*
    Contoh input:
    queueInput : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
    queueOutput: queue kosong

    Contoh output:
    queueInput:  [2,3,4,5,6]
    queueOutput: [2,3,4,5,6]
*/
    // KAMUS LOKAL
    int i, len = length(*queueInput);
    ElType val;
    // ALGORITMA
    for (i = 0; i < len; i++) {
        dequeue(queueInput, &val);
        enqueue(queueOutput, val);
        enqueue(queueInput, val);
    }
}