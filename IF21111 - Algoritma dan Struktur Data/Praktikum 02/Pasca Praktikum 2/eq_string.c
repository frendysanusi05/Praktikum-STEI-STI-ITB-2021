/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 24 September 2022
Topik praktikum: Pasca Praktikum 2 - Pengenalan C
Deskripsi: Menentukan apakah kedua string memiliki panjang yang sama dan huruf per hurufnya merupakan abjad yang sama
*/

#include <stdio.h>
#include <string.h>

int main() {
    // KAMUS
    char s1[100], s2[100];
    int i = 0, found = 1;
    // ALGORITMA
    scanf("%s %s", s1, s2);
    if (strlen(s1) == strlen(s2)) {
        while (i < strlen(s1) && found) {
            if (s1[i] >= 97) {
                s1[i] -= 32;
            }
            if (s2[i] >= 97) {
                s2[i] -= 32;
            }

            if (s1[i] != s2[i]) {
                found = 0;
            }
            i++;
        }
    } else {
        found = 0;
    }
    if (found == 1) {
        printf("Ya\n");
    } else {
        printf("Tidak\n");
    }
    return 0;
}