#include "prioqueuelist.h"
#include "stdlib.h"

/* Prototype manajemen memori */
address newNode(ElType x, int pr) {}
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x dan prio = pr,
atau NIL jika alokasi gagal */

void delNode(address P) {}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

boolean isEmpty(PrioQueue q) {}
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NIL and ADDR_TAIL(q)=NIL */

int length(Queue q) {}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
/*** Kreator ***/

void CreateQueue(PrioQueue *q) {}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */

/*** Primitif Enqueue/Dequeue ***/
void enqueue(PrioQueue *q, ElType x, int pr) {
/* Proses: Mengalokasi x dengan prio pr dan menambahkan x pada q jika alokasi berhasil; jika alokasi gagal q tetap */
/* I.S. q mungkin kosong */
/* F.S. x menjadi elemen q sesuai dengan urutan prioritas */
    // KAMUS LOKAL
    address p, prev, last;
    boolean add;
    // ALGORITMA
    add = false;
    p = newNode(x, pr);
    if (p != Nil) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = p;
        } else {
            prev = Nil;
            last = ADDR_HEAD(*q);
            while (last != Nil && !add) {
                if (PRIO(p) < PRIO(last)) {
                    if (last == ADDR_HEAD(*q)) {
                        ADDR_HEAD(*q) = p;
                    } else {
                        NEXT(prev) = p;
                    }
                    NEXT(p) = last;
                    add = true;
                } else {
                    prev = last;
                    last = NEXT(last);
                }
            }

            if (last == Nil) {
                NEXT(prev) = p;
            }
        }
    }
}

void dequeue(PrioQueue *q, ElType *x, int *pr) {
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
    // KAMUS LOKAL
    address p;
    // ALGORITMA
    *x = HEAD(*q);
    *pr = PRIO(ADDR_HEAD(*q));

    p = ADDR_HEAD(*q);
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    delNode(p);
}