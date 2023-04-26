/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 14 November 2022
Topik praktikum: Variasi List Linier
Deskripsi: Implementasi queuelist.h
*/

#include "queuelist.h"

/* Prototype manajemen memori */
void Alokasi(address *P, infotype X) {
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
	// KAMUS LOKAL
	// ALGORITMA
	*P = (ElmtQueue*) malloc (sizeof(ElmtQueue));
	if (*P != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void Dealokasi(address P) {
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
	// KAMUS LOKAL
	// ALGORITMA
	free(P);
}

boolean IsEmpty(Queue Q) {
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
	// KAMUS LOKAL
	// ALGORITMA
	return Head(Q)==Nil && Tail(Q)==Nil;
}

int NbElmt(Queue Q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
	// KAMUS LOKAL
	int cnt = 0;
	address p;
	// ALGORITMA
	p = Head(Q);
	if (IsEmpty(Q)) return 0;
	else {
		while (p != Tail(Q)) {
			p = Next(p);
			cnt++;
		}
		cnt++;
		return cnt;
	}
}

/*** Kreator ***/
void CreateEmpty(Queue *Q) {
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
	// KAMUS LOKAL
	// ALGORITMA
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}

/*** Primitif Add/Delete ***/
void Enqueue(Queue *Q, infotype X) {
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
	// KAMUS LOKAL
	address p, last;
	// ALGORITMA
	Alokasi(&p, X);
	last = Tail(*Q);
	if (p != Nil) {
		if (IsEmpty(*Q)) {
			Head(*Q) = p;
			Tail(*Q) = p;
		}
		else {
			Next(last) = p;
			Tail(*Q) = p;
		}
	}
}

void Dequeue(Queue *Q, infotype *X) {
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
	// KAMUS LOKAL
	address last;
	// ALGORITMA
	last = Head(*Q);
	*X = Info(last);
	Head(*Q) = Next(last);
	if (Head(*Q) == Nil) {
		CreateEmpty(Q);
	}
	Dealokasi(last);
}
