/*
Nama: Frendy Sanusi
NIM: 18221041
Kelas: K04
*/

#include <stdio.h>

void Holoh3ro(char *input) {
    int x, y, n, answer;

    n = scanf("%d %d", &x, &y);
    /* n adalah jumlah scanf yang sukses */
    
    if (n <= 1) {
        illegal_move();
    } else {
        if (x > 7 || x < 0) {
            illegal_move();
        } else {
            switch(x) {
                case 0:
                    answer = 534;
                    break;
                case 1:
                    answer = 752;
                    break;
                case 2:
                    answer = 893;
                    break;
                case 3:
                    answer = 314;
                    break;
                case 4:
                case 5:
                    answer = 470;
                    break;
                case 6:
                    answer = 139;
                    break;
                case 7:
                    answer = 745;
                    break;
                default:
                    illegal_move();
                    break;
            }

            if (answer + y != 0) {
                illegal_move();
            }
        }

    }
}