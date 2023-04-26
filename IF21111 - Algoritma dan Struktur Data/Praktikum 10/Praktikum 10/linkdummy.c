/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 14 November 2022
Topik praktikum: Variasi List Linier
Deskripsi: Implementasi linkdummy.h
*/

#include "linkdummy.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L) {
/* Mengirim true jika list kosong: First(L) = dummy@
dan Last(L) = dummy@ */
	// KAMUS LOKAL
	// ALGORITMA
	return First(L) == Last(L);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void MakeEmpty(List *L) {
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong, dengan satu elemen dummy */
/* Jika gagal maka First = Last = Nil dan list gagal terbentuk */\
	// KAMUS LOKAL
	address dummy;
	// ALGORITMA
	dummy = Alokasi(0);
	if (dummy != Nil) {
		First(*L) = dummy;
		Last(*L) = dummy;
	} else {
		First(*L) = Nil;
		Last(*L) = Nil;
	}
}

/****************** MANAJEMEN MEMORI ******************/
address Alokasi (ElType X) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
	// KAMUS LOKAL
	address p;
	// ALGORITMA
	p = (Node*) malloc (sizeof(Node));
	if (p != Nil) {
		Info(p) = X;
		Next(p) = Nil;
	}
	return p;
}

void Dealokasi (address P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
	free(P);
}

/****************** SEARCHING ******************/
address Search(List L, ElType X) {
/* Mencari apakah ada node list dengan info(P) = X */
/* Jika ada, mengirimkan address node tersebut. */
/* Jika tidak ada, mengirimkan Nil */
	// KAMUS LOKAL
	address p;
	// ALGORITMA
	p = First(L);
	Info(Last(L)) = X;
	while (Info(p) != X) {
		p = Next(p);
	}
	
	if (p != Last(L)) return p;
	else return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst(List *L, ElType X) {
/* I.S. List L terdefinisi */
/* F.S. Menambahkan elemen X sebagai elemen pertama List L */
	// KAMUS LOKAL
	address p;
	// ALGORITMA
	p = Alokasi(X);
	if (p != Nil) {
		Next(p) = First(*L);
		First(*L) = p;
	}
}

void InsertLast(List *L, ElType X) {
/* I.S. List L terdefinisi */
/* F.S. X ditambahkan sebagai elemen terakhir yang baru, */
/* yaitu menjadi elemen sebelum elemen dummy */
/* Alamat elemen dummy tidak berubah */
	// KAMUS LOKAL
	address p, last;
	// ALGORITMA
	p = Alokasi(X);
	
	if (p != Nil) {
		if (IsEmpty(*L)) InsertFirst(L, X);
		else {
			last = First(*L);
			while (Next(last) != Last(*L)) {
				last = Next(last);
			}
			Next(last) = p;
			Next(p) = Last(*L);
		}
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst(List *L, ElType *X) {
/* I.S. List tidak kosong */
/* F.S. X adalah elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
	// KAMUS LOKAL
	address p;
	// ALGORITMA
	p = First(*L);
	*X = Info(p);
	First(*L) = Next(p);
	Dealokasi(p);
}

void DeleteLast(List *L, ElType *X) {
/* I.S. List tidak kosong */
/* F.S. X adalah terakhir sebelum dummy pada list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
	// KAMUS LOKAL
	address p, prev;
	// ALGORITMA
	if (Next(First(*L)) == Last(*L)) DeleteFirst(L, X);
	else {
		p = First(*L);
		prev = Nil;
		while (Next(p) != Last(*L)) {
			prev = p;
			p = Next(p);
		}
		*X = Info(p);
		Next(prev) = Last(*L);
		Dealokasi(p);
	}
}
