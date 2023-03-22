/* 
Nama: Frendy Sanusi
NIM: 18221041
Kelas: K01
*/

#include <stdio.h>

void Uncover_Corps_Basement(char *input) {
    char answer[] = "Welcome to Holo Number 5.";
    
    if (strings_not_equal(input, answer)) {
    /* fungsi strings_not_equal akan mengembalikan true jika input sama dengan answer */
        illegal_move();
    }
}