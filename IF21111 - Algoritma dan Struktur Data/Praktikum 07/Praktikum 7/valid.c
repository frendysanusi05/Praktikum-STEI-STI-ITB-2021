/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 27 November 2022
Topik praktikum: Stack
Deskripsi: Implementasi "valid.h"
*/

#include "valid.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack validParantheses(char* input, int length) {
/* Proses: Memasukkan parantheses (dari input) yang valid secara berurutan ke dalam Stack */
/* I.S. input adalah string, yang berisi parantheses baik secara acak maupun teratur, dan panjang dari string */
/* Contoh input dan hasil parantheses yang valid:
    1. () 2 -> ()
    2. []) 3 -> []
    3. {[} 3 -> --kosong--
    4. ()[]{} 6 -> ()[]{}
*/
	// KAMUS LOKAL
	Stack S;
	int i = 0;
	int idx;
	// ALGORITMA
	CreateEmpty(&S);
	while (i < length-1) {
		idx = i+1;
		if (input[i] == '(') {
			if (input[idx] == ')') {
				Push(&S, input[i]);
				Push(&S, input[idx]);
			}
		} else if (input[i] == '[') {
			if (input[idx] == ']') {
				Push(&S, input[i]);
				Push(&S, input[idx]);
			}
		}  else if (input[i] == '{') {
			if (input[idx] == '}') {
				Push(&S, input[i]);
				Push(&S, input[idx]);
			}
		}
		i++;
	}
	
	return S;
}