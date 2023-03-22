/*
Nama: Frendy Sanusi
NIM: 18221041
Kelas: K01
*/

#include <stdio.h>

void Holoro(char *input) {
    int i;
    int arr[6];
    
    read_six_numbers(input, arr);

    if (arr[0] != 163) {
        illegal_move();
    } else {
        int num;
        for (num = 1; num < 6; num++) {
            if (arr[num] != (arr[num-1] / 2 ^ arr[num-1])) {
                illegal_move();
            }
        }
    }
}