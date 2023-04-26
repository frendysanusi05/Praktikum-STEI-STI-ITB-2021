/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 12 November 2022
Topik praktikum: Variasi list linier
Deskripsi: Mencari elemen ke-N dari sebuah list 
*/

#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
    // KAMUS LOKAL
    address p;
    int cnt = 0;
    // ALGORITMA
    p = First(L);
    while (cnt != r) {
        p = Next(p);
        cnt++;
    }
    return Info(p);
}

int main () {
    // KAMUS
    List L;
    int r, num;
    // ALGORITMA
    CreateEmpty(&L);
    scanf("%d", &num);
    while (num != 0) {
        InsVLast(&L, num);
        scanf("%d", &num);
    }
    scanf("%d", &r);

    if (IsEmpty(L)) printf("List Kosong\n");
    else printf("%d\n", ElemenKeN(L, r));
    return 0;
}