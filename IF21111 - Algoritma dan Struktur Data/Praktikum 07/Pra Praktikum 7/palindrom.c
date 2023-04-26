/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 21 Oktober 2022
Topik praktikum" Pra Praktikum 7 - Stack
Deskripsi: Memeriksa apakah sebuah stack merupakan stack yang palindrom atau tidak
*/

#include <stdio.h>
#include "stack.h"

int main() {
    // KAMUS
    int n; // masukan
    int cnt = 0;
    Stack S1, S2, S3; // S1 = S3, S2 = reverse dari S1
    // ALGORITMA
    CreateEmpty(&S1); CreateEmpty(&S2); CreateEmpty(&S3);
    scanf("%d", &n);
    while (n != 0) {
        Push(&S1, n);
        cnt++;
        scanf("%d", &n);
    }
    
    if (IsEmpty(S1)) {
        printf("Stack kosong\n");
    } else {
        while (!IsEmpty(S1)) {
            Pop(&S1, &n);
            Push(&S2, n);
            Push(&S3, n);
        }

        while (!IsEmpty(S3)) {
            Pop(&S3, &n);
            Push(&S1, n);
        }

        while (!IsEmpty(S1)) {
            if (InfoTop(S1) == InfoTop(S2)) {
                cnt--;
            }
            Pop(&S1, &n);
            Pop(&S2, &n);
        }

        if (cnt == 0) {
            printf("Palindrom\n");
        } else {
            printf("Bukan Palindrom\n");
        }
    }
    return 0;
}