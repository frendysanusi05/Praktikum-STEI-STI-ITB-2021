/*
Nama: Frendy Sanusi
NIM: 18221041
Kelas: K01
*/

#include <stdio.h>

void Secret_Society(char *input) {
    int a, b, n;
    char* c;
    
    n = scanf("%d %d", &a, &b);
    if ((n != 2) || (14 < a)) {
        illegal_move();
    }
    
    n = func4(a, 0, 14);
    if ((n != 13) || (b != 13)) {
        illegal_move();
    }
}

int func4(int param1, int param2, int param3) {
    int a, b;

    b = (param3 - param2) / 2 + param2;
    if (param1 < b) {
        a = func4(param1, param2, b-1);
        b += a;
    } else if (b < param1) {
        a = func4(param1, b+1, param3);
        b += a;
    }
    return b;
}