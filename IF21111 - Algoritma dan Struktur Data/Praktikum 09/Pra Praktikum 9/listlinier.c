/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 4 November 2022
Topik praktikum: Struktur Berkait
Deskripsi: Implementasi listlinier.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
/* Mengirim true jika list kosong */
    // KAMUS LOKAL
    // ALGORITMA
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    // KAMUS LOKAL
    // ALGORITMA
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    // KAMUS LOKAL
    address p;
    // ALGORITMA
    p = (ElmtList*) malloc (sizeof(ElmtList));

    if (p != Nil) {
        Info(p) = X;
        Next(p) = Nil;
        return p;
    } else {
        return Nil;
    }
}

void Dealokasi (address *P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    // KAMUS LOKAL
    // ALGORITMA
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X) {
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    // KAMUS LOKAL
    address p;
    boolean found = false;
    // ALGORITMA
    p = First(L);
    while (p != Nil && !found) {
        if (Info(p) == X) {
            found = true;
        } else {
            p = Next(p);
        }
    }

    if (found) {
        return p;
    } else {
        return Nil;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    // KAMUS LOKAL
    address p;
    // ALGORITMA
    p = Alokasi(X);
    if (p != Nil) {
        Next(p) = First(*L);
        First(*L) = p;
    }    
}

void InsVLast (List *L, infotype X) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    // KAMUS LOKAL
    address p, last;
    // ALGORITMA
    if (IsEmpty(*L)) InsVFirst(L, X);
    else {
        p = Alokasi(X);
        if (p != Nil) {
            last = First(*L);
            while (Next(last) != Nil) {
                last = Next(last);
            }
            Next(last) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X) {
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    // KAMUS LOKAL
    address p;
    // ALGORITMA
    p = First(*L);
    *X = Info(p);
    First(*L) = Next(p);
    Dealokasi(&p);
}

void DelVLast (List *L, infotype *X) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    // KAMUS LOKAL
    address p, prev;
    // ALGORITMA
    p = First(*L);
    while (Next(p) != Nil) {
        prev = p;
        p = Next(p);
    }

    *X = Info(p);

    if (NbElmt(*L) == 1) First(*L) = Nil;
    else Next(prev) = Nil;
    Dealokasi(&p);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    // KAMUS LOKAL
    // ALGORITMA
    if (P != Nil) {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsertAfter (List *L, address P, address Prec) {
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    // KAMUS LOKAL
    address last;
    // ALGORITMA
    if (P != Nil) {
        Next(P) = Next(Prec);
        Next(Prec) = P; 
    }
}

void InsertLast (List *L, address P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    // KAMUS LOKAL
    address last;
    // ALGORITMA
    if (IsEmpty(*L)) InsertFirst(L, P);
    else {
        if (last != Nil) {
            last = First(*L);
            while (Next(last) != Nil) {
                last = Next(last);
            }

            Next(last) = P;
        }
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    // KAMUS LOKAL
    // ALGORITMA
    *P = First(*L);
    First(*L) = Next(*P);
}

void DelP (List *L, infotype X) {
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    // KAMUS LOKAL
    address prev, last;
    // ALGORITMA
    last = First(*L);
    prev = Nil;
    while (Info(last) != X) {
        prev = last;
        last = Next(last);
    }

    if (last == First(*L)) First(*L) = Next(last);
    else Next(prev) = Next(last);
    Dealokasi(&last);
}

void DelLast (List *L, address *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
    // KAMUS LOKAL
    address last, prev;
    // ALGORITMA
    last = First(*L);
    while (Next(last) != Nil) {
        prev = last;
        last = Next(last);
    }
    *P = last;

    if (NbElmt(*L) == 1) First(*L) = Nil;
    else Next(prev) = Nil;
}

/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec) {
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    // KAMUS LOKAL
    // ALGORITMA
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    // KAMUS LOKAL
    address p;
    // ALGORITMA
    if (IsEmpty(L)) printf("[]\n");
    else {
        p = First(L);
        printf("[");
        while (p != Nil) {
            if (Next(p) != Nil) printf("%d,", Info(p));
            else printf("%d]", Info(p));
            p = Next(p);
        }
    }
}

int NbElmt (List L) {
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    // KAMUS LOKAL
    int cnt = 0;
    address p;
    // ALGORITMA
    p = First(L);
    while (p != Nil) {
        p = Next(p);
        cnt++;
    }
    return cnt;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L) {
/* Mengirimkan nilai info(P) yang maksimum */
    // KAMUS LOKAL
    int max;
    address p;
    // ALGORITMA
    p = First(L);
    max = Info(p);
    while (p != Nil) {
        if (Info(p) > max) max = Info(p);
        p = Next(p);
    }
    return max;
}

address AdrMax (List L) {
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    // KAMUS LOKAL
    address p;
    infotype max = Max(L);
    // ALGORITMA
    p = First(L);
    while (Info(p) != max) {
        p = Next(p);
    }
    return p;
}

infotype Min (List L) {
/* Mengirimkan nilai info(P) yang minimum */
    // KAMUS LOKAL
    int min;
    address p;
    // ALGORITMA
    p = First(L);
    min = Info(p);
    while (p != Nil) {
        if (Info(p) < min) min = Info(p);
        p = Next(p);
    }
    return min;
}

address AdrMin (List L) {
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    // KAMUS LOKAL
    address p;
    infotype min = Min(L);
    // ALGORITMA
    p = First(L);
    while (Info(p) != min) {
        p = Next(p);
    }
    return p;
}

float Average (List L) {
/* Mengirimkan nilai rata-rata info(P) */
    // KAMUS LOKAL
    float sum = 0, cnt = 0;
    address p;
    // ALGORITMA
    p = First(L);
    while (p != Nil) {
        sum += Info(p);
        p = Next(p);
        cnt++;
    }
    return sum/cnt;
}

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L) {
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
    // KAMUS LOKAL
    address p, prev, last;
    // ALGORITMA
    p = First(*L);
    prev = Nil;
    while (p != Nil) {
        last = p;
        p = Next(p);
        Next(last) = prev;
        prev = last;
    }

    First(*L) = last;
}

void Konkat1 (List *L1, List *L2, List *L3) {
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    // KAMUS LOKAL
    address last;
    // ALGORITMA
    if (IsEmpty(*L1)) First(*L3) = First(*L2);
    else {
        First(*L3) = First(*L1);
        last = First(*L1);
        while (Next(last) != Nil) {
            last = Next(last);
        }
        Next(last) = First(*L2);
    }

    First(*L1) = Nil;
    First(*L2) = Nil;
}