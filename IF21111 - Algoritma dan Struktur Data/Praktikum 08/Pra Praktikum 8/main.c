#include <stdio.h>
#include "hashmap.h"

void display(HashMap M) {
    // display HashMap
    int i;

    printf("Key: [");
    for (i = 0; i < MaxEl; i++) {
        if (i == MaxEl-1) {
            printf("%d]\n", M.Elements[i].Key);
        } else {
            printf("%d, ", M.Elements[i].Key);
        }
    }

    printf("Value: [");
    for (i = 0; i < MaxEl; i++) {
        if (i == MaxEl-1) {
            printf("%d]\n", M.Elements[i].Value);
        } else {
            printf("%d, ", M.Elements[i].Value);
        }
    }
}

int main() {
    HashMap M;

    CreateEmpty(&M);

    // isi HashMap
    Insert(&M, 50, 51);
    Insert(&M, 700, 701);
    Insert(&M, 76, 77);
    Insert(&M, 85, 86);
    Insert(&M, 92, 93);
    Insert(&M, 73, 74);
    Insert(&M, 101, 102);
    display(M);

    printf("Count: %d\n", M.Count);

    // printf("Value: %d\n", Value(M, 40));
    // printf("Value: %d\n", Value(M, 56));
    return 0;
}