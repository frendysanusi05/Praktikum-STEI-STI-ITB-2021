/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 21 Oktober 2022
Topik praktikum" Pra Praktikum 7 - Stack
Deskripsi: Implementasi aritmatika.h
*/

#include "stack.h"
#include "aritmatika.h"

boolean isOperator(char input) {
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari berikut:
                - +
                - -
                - *
                - /
*/
    // KAMUS LOKAL
    // ALGORITMA
    return (input == '+' || input == '-' || input == '*' || input == '/');
}

int hitung(int angka1, int angka2, char op) {
/* Proses: Menghitung ekspresi */
/*
    Contoh input / output:
    angka1 : 2
    angka2 : 10
    op     : -

    return : -8 (penjelasan: 2 - 10 = 8)
*/
    // KAMUS LOKAL
    // ALGORITMA
    if (op == '+') {
        return (angka1 + angka2);
    } else if (op == '-') {
        return (angka1 - angka2);
    } else if (op == '*') {
        return (angka1 * angka2);
    } else if (op == '/') {
        return (angka1 / angka2);
    }
}

int eval(char *input, int length) {
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
/*
    Contoh input / output:
    input   : 23+
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 2 + 3)

    input   : 9423+*5/-
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 9-(4*(2+3))/5)

*/
    // KAMUS LOKAL
    Stack S;
    int idx = 0;
    infotype angka1, angka2, angka;
    char op;
    // ALGORITMA
    CreateEmpty(&S);
    while (idx != length) {
        if (!isOperator(input[idx])) {
            angka = input[idx] - '0';
            Push(&S, angka);
        } else {
            op = input[idx];
            Pop(&S, &angka2);
            Pop(&S, &angka1);
            Push(&S, hitung(angka1, angka2, op));
        }
        idx++;
    }
    return (InfoTop(S));
}