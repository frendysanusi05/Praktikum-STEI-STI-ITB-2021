/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 7 November 2022
Topik praktikum: Struktur berkait
Deskripsi:
    Jika x ada di cache, nilai x dipindah ke depan cache.
    Jika x tidak ada di cache, nilai paling akhir dihapus dari cache dan x dimasukkan ke depan cache.
    Untuk setiap operasi, tuliskan apakah operasi "hit" atau "miss". Lalu, tuliskan isi list.

*/

#include <stdio.h>
#include "listlinier.h"

int main() {
	// KAMUS LOKAL
	List L;
	int N, Q, i, x;
	address p, temp;
	// ALGORITMA
	CreateEmpty(&L);
	scanf("%d", &N); scanf("%d", &Q);
	
	for (i = 1; i <= N; i++) {
		InsVLast(&L, i);
	}
	
	for (i = 0; i < Q; i++) {
		scanf("%d", &x);
		p = Search(L, x);
		if (p != Nil) {
			DelP(&L, x);
		} else {
			DelLast(&L, &temp);
		}
		InsVFirst(&L, x);
		
		if (p != Nil) {
			printf("hit ");
		} else {
			printf("miss ");
		}
		PrintInfo(L);
		printf("\n");
	}
	
	return 0;
}
