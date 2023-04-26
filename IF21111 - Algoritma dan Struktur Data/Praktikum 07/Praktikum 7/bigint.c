/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 27 November 2022
Topik praktikum: Stack
Deskripsi: Menghitung pengurangan tiap digit dari integer
*/

#include "stack.h"
#include <stdio.h>

int main() {
	// KAMUS LOKAL
	Stack S1, S2, S;
	int i = 0, j = 0, k = 0;
	char s1[101], s2[101];
	int temp1, temp2, temp = 0, ans;
	boolean neg = false;
	// ALGORITMA
	CreateEmpty(&S1); CreateEmpty(&S2); CreateEmpty(&S);
	scanf("%s", s1); scanf("%s", s2);
	
	while (s1[i] != '\0') {
		s1[i] -= '0';
		Push(&S1, s1[i]);
		i++;
	}
	i--;
	
	while (s2[j] != '\0') {
		s2[j] -= '0';
		Push(&S2, s2[j]);
		j++;
	}
	j--;
	
	if (i < j) neg = true;
	else if (i == j) {
		while (k <= i && !neg) {
			if (s1[k] < s2[k]) neg = true;
			else k++;
		}
	}

	while (!IsEmpty(S1) || !IsEmpty(S2)) {
		if (!IsEmpty(S1)) Pop(&S1, &temp1);
		else temp1 = 0;

		if (!IsEmpty(S2)) Pop(&S2, &temp2);
		else temp2 = 0;

		if (!neg) ans = temp1 - temp2 - temp;
		else ans = temp2 - temp1 - temp;

		if (ans < 0) {
			temp = 1;
			ans += 10;
		}
		else temp = 0;
		Push(&S, ans);
	}

	if (neg) printf("-");
	while (InfoTop(S) == 0) {
		Pop(&S, &temp);
	}

	if (IsEmpty(S)) printf("0");
	else {
		while (!IsEmpty(S)) {
			Pop(&S, &temp);
			printf("%d", temp);
		}
	}
	printf("\n");
	return 0;
}