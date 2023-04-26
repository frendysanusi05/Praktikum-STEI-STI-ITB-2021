/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 14 November 2022
Topik praktikum: Variasi List Linier
Deskripsi: Implementasi linkstack.h
*/

#include "linkstack.h"

/* ********* PROTOTYPE MANAJEMEN MEMORI ********* */
void Alokasi(address *P, ElType X) {
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/* P=Nil jika alokasi gagal */
	// KAMUS LOKAL
	// ALGORITMA
	*P = (Node*) malloc (sizeof(Node));
	if (*P != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void Dealokasi(address P) {
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
	// KAMUS LOKAL
	// ALGORITMA
	free(P);
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty(Stack S) {
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
	// KAMUS LOKAL
	// ALGORITMA
	return Top(S) == Nil;
}

void CreateEmpty(Stack *S) {
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
	// KAMUS LOKAL
	// ALGORITMA
	Top(*S) = Nil;
}

void Push(Stack *S, ElType X) {
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/* jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
	// KAMUS LOKAL
	address p;
	// ALGORITMA
	Alokasi(&p, X);
	if (p != Nil) {
		Next(p) = Top(*S);
		Top(*S) = p;
	}
}

void Pop(Stack *S, ElType *X) {
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/* elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
	// KAMUS LOKAL
	address p;
	// ALGORITMA
	p = Top(*S);
	*X = Info(p);
	Top(*S) = Next(p);
	Dealokasi(p);
}
