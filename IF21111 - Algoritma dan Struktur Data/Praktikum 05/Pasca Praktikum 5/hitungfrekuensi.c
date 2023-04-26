/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 22 Oktober 2022
Topik praktikum: Pasca Praktikum 5 - Mesin Karakter
Deskripsi: Implementasi hitungfrekuensi.h
*/

#include <stdio.h>
#include "hitungfrekuensi.h"

char karakter(cc) {
	// KAMUS LOKAL
	char kar;
	// ALGORITMA
	kar = cc;
	if ((cc >= 65) && (cc <= 90)) {
		kar = cc + 32;
	}
	return kar;
}

int hitungfrekuensi() {
	// KAMUS LOKAL
	char kar;
	int cnt = 0;
	// ALGORITMA
	START();
	while (!IsEOP()) {
		kar = karakter(GetCC());
		if (kar == 't') {
			ADV();
			kar = karakter(GetCC());
			if (kar == 'i') {
				ADV();
				kar = karakter(GetCC());
				if (kar == 'g') {
					ADV();
					kar = karakter(GetCC());
					if (kar == 'a') {
						cnt++;
						ADV();
						kar = karakter(GetCC());
					}
				}
			}
		} else {
			ADV();
		}
	}
	return cnt;
}
