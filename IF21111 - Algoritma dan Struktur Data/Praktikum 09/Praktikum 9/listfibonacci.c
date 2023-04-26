/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 7 November 2022
Topik praktikum: Struktur berkait
Deskripsi: Membuat list fibonacci berdasarkan masukan jumlah elemen pada list

*/

#include <stdio.h>
#include "listlinier.h"

int main() {
	// KAMUS LOKAL
    List fibonacci;
    infotype el, x;
    int i, numBefore, numAfter;
    // ALGORITMA
    CreateEmpty(&fibonacci);
    scanf("%d", &el);

    // Masukkan kode program disini

    if (el == 0) {
        // Masukkan kode program disini
 
        PrintInfo(fibonacci);
        return 0;
    } else if (el == 1) {
        // Masukkan kode program disini
		scanf("%d", &x);
		InsVLast(&fibonacci, x);
        PrintInfo(fibonacci);
        return 0;
    } else {
        // Masukkan kode program disini
        for (i = 0; i < 2; i++) {
			scanf("%d", &x);
			InsVLast(&fibonacci, x);
			if (i == 0) numBefore = x;
			else numAfter = x;
		}
		
		if (el > 2) {
			for (i = 0; i < el-2; i++) {
				InsVLast(&fibonacci, numBefore + numAfter);
				numAfter += numBefore;
				numBefore = numAfter - numBefore;
			}
		}
        
        PrintInfo(fibonacci);
    }

    return 0;
}
