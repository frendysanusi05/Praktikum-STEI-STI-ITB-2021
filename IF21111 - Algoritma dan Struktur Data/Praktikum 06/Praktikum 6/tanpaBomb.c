/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 22 Oktober 2022
Topik praktikum: Queue - Pasca Praktikum 6
Deskripsi: Impelementasi tanpaBomb.h
*/

#include "tanpaBomb.h"

Queue tanpaBomb(Queue queue, ElType bomb) {
/* Mengembalikan sebuah queue yang sudah tidak memiliki nilai bomb */

/*
    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 3
    Contoh output: [2,4,5,6]

    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 7
    Contoh output: [2,3,4,5,6]

*/
    // KAMUS LOKAL
    Queue q;
    int i, val, len = length(queue);
    // ALGORITMA
    CreateQueue(&q);
    for (i = 0; i < len; i++) {
        dequeue(&queue, &val);

        if (val != bomb) {
            enqueue(&q, val);
        }
    }
    return q;
}