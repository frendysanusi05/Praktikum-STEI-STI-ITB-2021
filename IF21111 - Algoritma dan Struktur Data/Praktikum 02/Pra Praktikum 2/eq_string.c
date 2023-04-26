/*
NIM: 18221041
Nama: Frendy Sanusi
Tanggal: 11 September 2022
Topik praktikum: Pengenalan C
Deskripsi: Menentukan apakah kedua string sama dengan kedua string dikatakan sama apabila memiliki panjang yang sama dan huruf per hurufnya merupakan abjad yang sama.
*/

// File eq_string.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // KAMUS
    char *word1, *word2;
    int i = 0;
    word1 = (char *) malloc (100* sizeof(char));
    word2 = (char *) malloc (100* sizeof(char));
    // ALGORITMA
    scanf("%s", word1);
    scanf("%s", word2);
    while (i <= strlen(word1)) {
        if ((word1[i] >= 65) && (word1[i] <= 90)) {
            word1[i] += 32; // membuat huruf kapital menjadi huruf kecil
        }
        if ((word2[i] >= 65) && (word2[i] <= 90)) {
            word2[i] += 32; // membuat huruf kapital menjadi huruf kecil
        }
        if (word1[i] == word2[i]) {
            i++;
        } else {
            printf("Tidak\n");
            break;
        }
    }
    if ((i - 1) == strlen(word1)) {
        printf("Ya\n");
    }
    return 0;
}