/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 27 November 2022
Topik praktikum: Stack
Deskripsi: Implementasi "browserhistory.h"
*/

#include "browserhistory.h"

void browserHistoryVisit(Stack *openedTab, Stack *history, char *url) {
/**
 * Menambahkan url ke openedTab
 * I.S. openedTab mungkin kosong, tabel penampung elemen stack TIDAK penuh
 * F.S. url menjadi TOP yang baru, TOP bertambah 1, history kosong
 */
	// KAMUS LOKAL
	// ALGORITMA
	Push(openedTab, url);
	Push(history, url);
}

char *currentUrl(Stack *openedTab) {
/**
 * Mengembalikan url yang sedang dibuka
 * I.S. openedTab tidak mungkin kosong
 * F.S. url adalah nilai elemen TOP yang lama
 */
	// KAMUS LOKAL
	// ALGORITMA
	return (InfoTop(*openedTab));
}

char *browserHistoryBack(Stack *openedTab, Stack *history, int steps) {
/**
 * Mengembalikan url yang sedang dibuka setelah kembali ke sebelumnya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak langkah yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP berkurang 1
 */
	// KAMUS LOKAL
	int i;
	infotype url;
	// ALGORITMA
	for (i = 0; i < steps; i++) {
		Pop(openedTab, &url);
		Push(history, url);
	}
	return currentUrl(openedTab);
}

char *browserHistoryForward(Stack *openedTab, Stack *history, int steps) {
/**
 * Mengembalikan url yang sedang dibuka setelah maju ke depannya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak langkah yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP bertambah 1
 */
	// KAMUS LOKAL
	int i;
	infotype url;
	// ALGORITMA
	for (i = 0; i < steps; i++) {
		Pop(history, &url);
		Push(openedTab, url);
	}
	return currentUrl(openedTab);
}

void browserHistoryFree(Stack *history) {
/**
 * Mengosongkan history
 * I.S. history tidak mungkin kosong
 * F.S. history kosong
 */
	// KAMUS LOKAL
	infotype X;
	// ALGORITMA
	while (!IsEmpty(*history)) {
		Pop(history, &X);
	}
}
