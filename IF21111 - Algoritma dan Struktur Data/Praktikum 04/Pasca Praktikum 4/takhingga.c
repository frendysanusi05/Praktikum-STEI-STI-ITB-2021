/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 28 September 2022
Topik praktikum: Pasca Praktikum 4 - Array dan ADT List
Deskripsi: Menghitung penjumlahan bilangan dari posisi l sampai posisi ke r
*/

#include <stdio.h>

int main() {
    // KAMUS LOKAL
    int N, q, l, r;
    long long sum = 0;
    // ALGORITMA
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        for (int j = l-1; j <= r-1; j++) {
            sum += arr[j % N];
        }
        printf("%lld\n", sum);
        sum = 0;
    }
    return 0;
}