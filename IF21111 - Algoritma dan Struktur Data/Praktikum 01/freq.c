/*
NIM: 18221041
Nama: Frendy Sanusi
Tanggal: 11 September 2022
Topik: Pengenalan C
Deskripsi: Menentukan banyaknya frekuensi angka 0-9 dalam string masukan
*/

// File freq.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // KAMUS
    char *word;
    word = (char *) malloc (20* sizeof(char));
    int arr[10] = {0}, i, j = 0;
    // ALGORITMA
    scanf("%s", word);
    for (i = 0; i <= strlen(word); i++) {
        while (j <= 9) {
            if (word[i] == 48 + j) {
                arr[j] += 1;
                break;
            } else {
                j++;
            }
        }
        j = 0;
    }
    for (i = 0; i <= 9; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}