/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 22 Oktober 2022
Topik praktikum: Pasca Praktikum 5 - Mesin Karakter
Deskripsi: Membuat enkripsi dengan Caesar Cipher
*/

#include <stdio.h>
#include "boolean.h"
#include "mesinkarakterv2.h"
#include "mesinkata.h"

//Word currentWord;

int main() {
	// KAMUS
	int firstLength, i;
	// ALGORITMA
	STARTWORD();
	firstLength = currentWord.Length % 26;
	while (!isEndWord()) {
		for (i = 0; i < currentWord.Length; i++) {
			currentWord.TabWord[i] = (currentWord.TabWord[i] + firstLength) % 91;
			if (currentWord.TabWord[i] < 65) {
				currentWord.TabWord[i] += 65;
			}
			printf("%c", currentWord.TabWord[i]);
		}
		IgnoreBlanks();
		ADVWORD();
		
		if (!isEndWord()) {
			printf(" ");
		}
	}
	printf(".\n");
	return 0;
}

