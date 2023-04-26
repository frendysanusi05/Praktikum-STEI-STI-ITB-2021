#include <stdio.h>
#include "listdp.h"
// #include "listsirkuler.h"

int main() {
    // KAMUS LOKAL
    List L;
    int X;
    address p;
    // ALGORITMA
    CreateEmpty(&L);
    // printf("IsEmpty: %d\n", IsEmpty(L));
    // InsVFirst(&L, 3);
    // p = Search(L, 3);
    InsVFirst(&L, 2);
    // InsVLast(&L, 5);
    // InsVLast(&L, 7);

    // printf("Info: %d\n", Info(Search(L,2)));
    // DelLast(&L, &p);
    // p = Alokasi(3);
    // InsertBefore(&L, p, Search(L, 2));
    // InsertFirst(&L, p);
    // DelP(&L, 2);
    // InsertAfter(&L, p, Search(L, 2));
    // DelVLast(&L, &X);
    // DelAfter(&L, &p, Search(L, 2));
    DelBefore(&L, &p, Search(L, 2));

    // PrintInfo(L);
    PrintForward(L);
    printf("\n");
    PrintBackward(L);
    printf("\n");
    // printf("X: %d\n", X);
    return 0;
}