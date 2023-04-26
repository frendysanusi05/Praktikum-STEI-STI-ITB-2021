/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 22 Oktober 2022
Topik praktikum: Queue - Pasca Praktikum 6
Deskripsi:  Menghitung jumlah masakan yang disaji, waktu minimal yang dibutuhkan, dan waktu maksimal yang dibutuhkan
*/

#include <stdio.h>
#include "queue.h"

int main() {
    // KAMUS
    Queue q;
    int masukan, waktu, max = -1, min = 999, cnt = 0;
    // ALGORITMA
    CreateQueue(&q);
    scanf("%d", &masukan);
    while (masukan != 0) {
        if (masukan == 1) {
            scanf("%d", &waktu);
            if (waktu > 0) {
                enqueue(&q, waktu);
            }
        } else if (masukan == 2) {
            if (!isEmpty(q)) {
                cnt++;
                dequeue(&q, &waktu);
                if (waktu > max) {
                    max = waktu;
                }
                if (waktu < min) {
                    min = waktu;
                }
            }
        }
        scanf("%d", &masukan);
    }
    if (cnt == 0) {
        max = 0;
        min = 0;
    }
    printf("%d\n%d\n%d\n", cnt, min, max);
    return 0;
}