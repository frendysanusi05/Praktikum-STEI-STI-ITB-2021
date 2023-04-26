/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 5 November 2022
Topik praktikum: Struktur Berkait
Deskripsi: Implementasi OddEvenList.h
*/

#include "OddEvenList.h"

void OddEvenList(List L, List *Odd, List *Even) {
    /* Memisahkan elemen ganjil dan genap dari list L kedalam dua list baru secara mengurut membesar*/
    /* I.S: List L TIDAK mungkin kosong dan memiliki nilai lebih dari sama dengan 0(value>=0), List Odd dan Even kosong*/
    /* F.S: List Odd memiliki elemen bernilai ganjil mengurut membesar, List Even memiliki elemen bernilai genap mengurut membesar
            List L TIDAK PERLU DIDEALOKASI*/
    /*Contoh:
        Input:
            L: [0,3,1,4,5]
            Odd: []
            Even: []
        Output:
            L: [0,3,1,4,5]
            Odd: [1,3,5]
            Even: [0,4] */
    /*Note: 
        1. Bilangan 0 merupakan bilangan genap
        2. Buatlah List Odd dan Even terlebih dahulu*/
    // KAMUS LOKAL
    address p, last;
    int len = NbElmt(L), lenOdd, lenEven, i, min;
    List CopyOdd, CopyEven;
    boolean found = false;
    // ALGORITMA
    CreateEmpty(&CopyOdd); CreateEmpty(&CopyEven); CreateEmpty(Odd); CreateEmpty(Even);

    last = First(L);
    for (i = 0; i < len; i++) {
        p = Alokasi(Info(last));
        if (Info(last) % 2 == 0) InsertLast(&CopyEven, p);
        else InsertLast(&CopyOdd, p);
        last = Next(last);
    }
    
    lenOdd = NbElmt(CopyOdd);
    lenEven = NbElmt(CopyEven);

    for (i = 0; i < lenOdd; i++) {
        p = First(CopyOdd);
        min = Min(CopyOdd);
        while (p != Nil && !found) {
            if (Info(p) == min) {
                DelP(&CopyOdd, Info(p));
                InsVLast(Odd, min);
                found = true;
            } else {
                p = Next(p);
            }
        }
        found = false;
    }

    for (i = 0; i < lenEven; i++) {
        p = First(CopyEven);
        min = Min(CopyEven);
        while (p != Nil && !found) {
            if (Info(p) == min) {
                DelP(&CopyEven, Info(p));
                InsVLast(Even, min);
                found = true;
            } else {
                p = Next(p);
            }
        }
        found = false;
    }
}