/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 7 November 2022
Topik praktikum: Struktur berkait
Deskripsi: Implementasi removeDuplicate.h
*/

#include <stdio.h>
#include "removeDuplicate.h"

List removeDuplicate(List l) {

/*
    Diberikan sebuah list linier yang sudah terurut membesar,
    kembalikan list baru yang elementnya unik
    Contoh input/output:
    input:  [1,1,2,2,3,4,5,6,6,7]
    output: [1,2,3,4,5,6,7]

    input:  [1,1,1,1,1,1]
    output: [1]
*/

	// KAMUS LOKAL
	List L;
	address last, p;
	// ALGORITMA
	CreateEmpty(&L);
	last = First(l);
	while (last != Nil) {
		p = Search(L, Info(last));
		if (p == Nil) InsVLast(&L, Info(last));
		last = Next(last);
	}
	return L;
}
