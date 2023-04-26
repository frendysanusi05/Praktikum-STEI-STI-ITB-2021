/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 22 Oktober 2022
Topik praktikum: Pasca Praktikum 5 - Mesin Karakter
Deskripsi: Menghitung jumlah kata yang bersifat anagram alstrukdat
*/

#include <stdio.h>
#include <string.h>
#include "anagramalstrukdat.h"

/*  Menerima sebuah parameter string bertipe string
    Mengirimkan panjang sebuah string */
int stringLength (char* string) {
	// KAMUS LOKAL
	int i = 0;
	// ALGORITMA
	while (string[i] != '\0') {
		i++;
	}
	return i;
}

/*  Menerima sebuah paramater command bertipe string
    Mengirimkan kata yang elemen of arraynya berasal dari command */
Word toKata(char* command) {
	// KAMUS LOKAL
	int i = 0;
	Word kata;
	// ALGORITMA
	while (command[i] != '\0') {
		kata.TabWord[i] = command[i];
		i++;
	}
	kata.Length = stringLength(command);
	return kata;
}

/*  Menerima dua buah parameter yaitu string1 dan string2
    Mengembalikan true apabila string2 merupakan anagram dari string1
    Mengembalikan false apabila string2 bukan merupakan anagram dari string1
    String dianggap anagram apabila disusun dari huruf yang tepat sama */
boolean isAnagram(Word string1, Word string2) {
	// KAMUS LOKAL
	int i = 0, freq1[26] = {0}, freq2[26] = {0};
	// ALGORITMA
	if (string1.Length != string2.Length) {
		return false;
	} else {
		while (i < string1.Length) {
			freq1[string1.TabWord[i] - 'a']++;
			freq2[string2.TabWord[i] - 'a']++;
			i++;
		}

		for (i = 0; i < 26; i++) {
			if (freq1[i] != freq2[i]) {
				return false;
			}
		}
	}
	return true;
}

/*  Mengembalikan jumlah frekuensi kemunculan anagram alstrukdat 
    pada argumen frek */
void anagramalstrukdat(int* frek) {
	// KAMUS LOKAL
	Word alstrukdat;
	char alstrdat[] = "alstrukdat";
	int cnt = 0;
	// ALGORITMA
	alstrukdat = toKata(alstrdat);

	STARTWORD();
	IgnoreBlanks();

	while (!isEndWord()) {
		if (isAnagram(currentWord, alstrukdat)) {
			cnt++;
		}
		ADVWORD();
	}
	*frek = cnt;
}
