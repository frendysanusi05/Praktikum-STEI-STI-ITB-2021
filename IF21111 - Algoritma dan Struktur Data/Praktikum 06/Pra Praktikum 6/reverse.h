#ifndef __reverse_h__
#define __reverse_h__

#include "circular_queue.h"

void transferReverse(Queue* q1, Queue* q2);
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik

#endif