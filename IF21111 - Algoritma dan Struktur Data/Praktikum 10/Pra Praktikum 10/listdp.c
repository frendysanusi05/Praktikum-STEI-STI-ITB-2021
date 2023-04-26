/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 11 November 2022
Topik praktikum: Variasi list linier
Deskripsi: Implementasi listdp.h
*/

#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    // KAMUS LOKAL
    // ALGORITMA
    return First(L) == Nil && Last(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    // KAMUS LOKAL
    // ALGORITMA
    First(*L) = Nil;
    Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
    // KAMUS LOKAL
    address p;
    // ALGORITMA
    p = (ElmtList*) malloc (sizeof(ElmtList));
    if (p == Nil) return Nil;
    else {
        Info(p) = X;
        Next(p) = Nil;
        Prev(p) = Nil;
        return p;
    }
}

void Dealokasi (address P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    // KAMUS LOKAL
    // ALGORITMA
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X) {
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    // KAMUS LOKAL
    address p;
    boolean found = false;
    // ALGORITMA
    p = First(L);
    while (!found && p != Nil) {
        if (Info(p) == X) found = true;
        else p = Next(p);
    }

    if (found) return p;
    else return Nil;
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
        InsertFirst(L, p);
    }
}

void InsVLast (List *L, infotype X) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    // KAMUS LOKAL
    address p;
    // ALGORITMA
    p = Alokasi(X);
    if (p != Nil) {
        InsertLast(L, p);
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
    DelFirst(L, &p);
    *X = Info(p);
    Dealokasi(p);
}

void DelVLast (List *L, infotype *X) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    // KAMUS LOKAL
    address p;
    // ALGORITMA
    DelLast(L, &p);
    *X = Info(p);
    Dealokasi(p);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    // KAMUS LOKAL
    // ALGORITMA
    if (P != Nil) {
        if (IsEmpty(*L)) Last(*L) = P;
        else {
            Next(P) = First(*L);
            Prev(First(*L)) = P;
        }
        First(*L) = P;
    }
}

void InsertLast (List *L, address P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    // KAMUS LOKAL
    // ALGORITMA
    if (P != Nil) {
        if (IsEmpty(*L)) InsertFirst(L, P);
        else {
            Next(Last(*L)) = P;
            Prev(P) = Last(*L);
            Last(*L) = P;
        }
    }
}

void InsertAfter (List *L, address P, address Prec) {
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    // KAMUS LOKAL
    // ALGORITMA
    if (Last(*L) != Prec) {
        Next(P) = Next(Prec);
        Next(Prec) = P;
        Prev(P) = Prec;
        Prev(Next(P)) = P;
    } else {
        InsertLast(L, P);
    }
}

void InsertBefore (List *L, address P, address Succ) {
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
    // KAMUS LOKAL
    // ALGORITMA
    if (Prev(Succ) == Nil) InsertFirst(L, P);
    else {
        Prev(P) = Prev(Succ);
        Next(Prev(Succ)) = P;
        Prev(Succ) = P;
        Next(P) = Succ;
    }    
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    // KAMUS LOKAL
    address last;
    // ALGORITMA
    last = First(*L);
    *P = last;

    if (First(*L) != Last(*L)) {
        First(*L) = Next(last);
        Prev(First(*L)) = Nil;
        Next(*P) = Nil;
        Prev(*P) = Nil;
    } else {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
}

void DelLast (List *L, address *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
    // KAMUS LOKAL
    address last;
    // ALGORITMA
    last = Last(*L);
    *P = last;

    if (First(*L) != last) {
        Last(*L) = Prev(last);
        Next(Last(*L)) = Nil;
        Next(*P) = Nil;
        Prev(*P) = Nil;
    } else {
        DelFirst(L, P);
    }
}

void DelP (List *L, infotype X) {
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    // KAMUS LOKAL
    address p;
    boolean found = false;
    // ALGORITMA
    p = First(*L);
    while (!found && p != Nil) {
        if (Info(p) == X) {
            found = true;
        } else {
            p = Next(p);
        }
    }

    if (found) {
        if (p == First(*L)) {
            DelFirst(L, &p);
        } else if (p == Last(*L)) {
            DelLast(L, &p);
        } else {
            Next(Prev(p)) = Next(p);
            Prev(Next(p)) = Prev(p);
        }
    }
    Dealokasi(p);
}

void DelAfter (List *L, address *Pdel, address Prec) {
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    // KAMUS LOKAL
    // ALGORITMA
    if (Prec == Last(*L)) {

    }
    else if (Next(Prec) == Last(*L)) {
        DelLast(L, Pdel);
    }
    else {
        *Pdel = Next(Prec);
        Next(Prec) = Next(*Pdel);
        Prev(Next(*Pdel)) = Prec;
        Next(*Pdel) = Nil;
        Prev(*Pdel) = Nil;
    }
}

void DelBefore (List *L, address *Pdel, address Succ) {
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    // KAMUS LOKAL
    // ALGORITMA
    if (Succ == First(*L)) {

    }
    else if (Prev(Succ) == First(*L)) DelFirst(L, Pdel);
    else {
        *Pdel = Prev(Succ);
        Next(Prev(*Pdel)) = Succ;
        Prev(Succ) = Prev(*Pdel);
        Next(*Pdel) = Nil;
        Prev(*Pdel) = Nil;
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    // KAMUS LOKAL
    address p;
    // ALGORITMA
    if (IsEmpty(L)) printf("[]");
    else {
        printf("[");
        p = First(L);
        while (p != Last(L)) {
            printf("%d,", Info(p));
            p = Next(p);
        }
        printf("%d]", Info(p));
    }
}

void PrintBackward (List L) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    // KAMUS LOKAL
    address p;
    // ALGORITMA
    if (IsEmpty(L)) printf("[]");
    else {
        printf("[");
        p = Last(L);
        while (p != First(L)) {
            printf("%d,", Info(p));
            p = Prev(p);
        }
        printf("%d]", Info(p));
    }
}