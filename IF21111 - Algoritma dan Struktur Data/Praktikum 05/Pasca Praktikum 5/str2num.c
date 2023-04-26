#include "wordmachine.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

boolean IsKataEqual(char *k1, char *k2) {
    if (strlen(k1) == strlen(k2)) {
        int i;
        for (i = 0; i < strlen(k1); i++) {
            if (k1[i] != k2[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

int main() {
    boolean angka = true;
    boolean Ada = true;
    int digit = 0;
    int digitNow = 0;
    STARTWORD();
    char *kata;
    kata = (char*) malloc (50 *sizeof(char));
    while (!EndWord) {
        strcpy(kata, currentWord.TabWord);
        while (angka) {
            if (IsKataEqual(kata, "seratus")) {
                digit += 100;
            } else if (IsKataEqual(kata, "sepuluh")) {
                digit += 10;
            } else if (IsKataEqual(kata, "satu")) {
                digit += 1;
            } else if (IsKataEqual(kata, "dua")) {
                digit += 2;
            } else if (IsKataEqual(kata, "tiga")) {
                digit += 3;
            } else if (IsKataEqual(kata, "empat")) {
                digit += 4;
            } else if (IsKataEqual(kata, "lima")) {
                digit += 5;
            } else if (IsKataEqual(kata, "enam")) {
                digit += 6;
            } else if (IsKataEqual(kata, "tujuh")) {
                digit += 7;
            } else if (IsKataEqual(kata, "delapan")) {
                digit += 8;
            } else if (IsKataEqual(kata, "sembilan")) {
                digit += 9;
            } else {
                // if ((!IsKataEqual(kata, "puluh")) && (!IsKataEqual(kata, "ratus"))) {
                //     angka = false;}
                if (IsKataEqual(kata, "puluh")) {
                    digit *= 10;
                } else if (IsKataEqual(kata, "ratus")) {
                    digit *= 100;
                } else {
                    angka = false;
                }
                digitNow += digit;
                digit = 0;
            }
            
            ADVWORD();
            if (EndWord) {
                angka = false;
                digitNow += digit;
            }
            // printf("%d %d\n", digit, digitNow);
        }

        if (digitNow != 0) {
            printf("%d ", digit);
        } else {
            printf("%s ", kata);
        }
        ADVWORD();
    }
    
    printf("\n");
    return 0;
}