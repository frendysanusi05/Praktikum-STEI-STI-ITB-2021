/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 11 November 2022
Topik praktikum: Variasi list linier
Deskripsi: Implementasi listsirkuler.h
*/

#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    // KAMUS LOKAL
    // ALGORITMA
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    // KAMUS LOKAL
    // ALGORITMA
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    // KAMUS LOKAL
    address p;
    // ALGORITMA
    p = (ElmtList*) malloc (sizeof(ElmtList));
    if (p == Nil) return Nil;
    else {
        Info(p) = X;
        Next(p) = Nil;
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
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    // KAMUS LOKAL
    address p;
    boolean found = false;
    // ALGORITMA
    if (IsEmpty(L)) return Nil;
    else {
        p = First(L);
        while (Next(p) != First(L) && !found) {
            if (Info(p) == X) found = true;
            else p = Next(p);
        }
    }
    if (Info(p) == X) found = true;

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
    if (p != Nil) InsertFirst(L, p);
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
    if (p != Nil) InsertLast(L, p);
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X) {
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

void DelVLast (List *L, infotype * X) {
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
    InsertLast(L, P);
    First(*L) = P;
}

void InsertLast (List *L, address P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    // KAMUS LOKAL
    address last;
    // ALGORITMA
    if (IsEmpty(*L)) {
        First(*L) = P;
        Next(P) = P;
    }
    else {
        last = First(*L);
        while (Next(last) != First(*L)) {
            last = Next(last);
        }
        Next(last) = P;
        Next(P) = First(*L);
    }
}

void InsertAfter (List *L, address P, address Prec) {
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    // KAMUS LOKAL
    // ALGORITMA
    Next(P) = Next(Prec);
    Next(Prec) = P;
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
    *P = First(*L);
    if (Next(*P) == First(*L)) First(*L) = Nil;
    else {
        last = First(*L);
        while (Next(last) != *P) {
            last = Next(last);
        }
        First(*L) = Next(*P);
        Next(last) = First(*L);
    }
}

void DelLast (List *L, address *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
    // KAMUS LOKAL
    address last;
    // ALGORITMA
    if (Next(First(*L)) == First(*L)) {
		*P = First(*L);
		First(*L) = Nil;
	} else {
		last = First(*L);
		while (Next(Next(last)) != First(*L)) {
			last = Next(last);
		}
		*P = Next(last);
		Next(last) = First(*L);
	}
}

void DelAfter (List *L, address *Pdel, address Prec) {
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    // KAMUS LOKAL
    // ALGORITMA
    *Pdel = Next(Prec);
    if (Next(Prec) == Prec) First(*L) = Nil;
    else if (Next(Prec) == First(*L)) DelFirst(L, Pdel);
    else Next(Prec) = Next(*Pdel);
}

void DelP (List *L, infotype X) {
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    // KAMUS LOKAL
    address p, last;
    // ALGORITMA
    p = Search(*L, X);
    if (p != Nil) {
        last = First(*L);
        while (Next(last) != p) {
            last = Next(last);
        }
        DelAfter(L, &p, last);
        Dealokasi(p);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
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
        while (Next(p) != First(L)) {
            printf("%d,", Info(p));
            p = Next(p);
        }
        printf("%d]", Info(p));
    }
}