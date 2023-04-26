/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 25 September 2022
Topik praktikum: Pra Praktikum 4 - Array dan ADT List
Deskripsi: Implementasi array.h
*/

#include "array.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabInt *T) {
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    // KAMUS LOKAL
    // ALGORITMA
    T->Neff = 0;
    T->TI[IdxMax - IdxMin + 1];
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T) {
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T) {
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    // KAMUS LOKAL
    // ALGORITMA
    return IdxMax;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
    // KAMUS LOKAL
    // ALGORITMA
    return IdxMin;
}

IdxType GetLastIdx (TabInt T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff;
}

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabInt T, IdxType i) {
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
    // KAMUS LOKAL
    // ALGORITMA
    return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabInt Tin, TabInt *Tout) {
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    MakeEmpty(Tout);
    for (i = 1; i <= Tin.Neff; i++) {
        Tout->TI[i] = Tin.TI[i];
    }
    Tout->Neff = Tin.Neff;
}

/* Assignment THsl -> Tin */
void SetEl (TabInt *T, IdxType i, ElType v) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
    // KAMUS LOKAL
    // ALGORITMA
    T->TI[i] = v;
    if (i > GetLastIdx(*T)) {
        T->Neff++;
    }
}

void SetNeff (TabInt *T, IdxType N) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
    // KAMUS LOKAL
    // ALGORITMA
    T->Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i) {
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    // KAMUS LOKAL
    // ALGORITMA
    return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff (TabInt T, IdxType i) {
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    // KAMUS LOKAL
    // ALGORITMA
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T) {
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    // KAMUS LOKAL
    // ALGORITMA
    return (T.Neff == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T) {
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    // KAMUS LOKAL
    // ALGORITMA
    return (T.Neff == IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabInt T) {
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    if (IsEmpty(T)) {
        printf("Tabel kosong\n");
    } else {
        for (i = IdxMin; i <= T.Neff; i++) {
            printf("%d:%d\n", i, T.TI[i]);
        }
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2) {
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
    // KAMUS LOKAL
    int i;
    TabInt tab;
    // ALGORITMA
    for (i = 1; i <= T1.Neff; i++) {
        tab.TI[i] = T1.TI[i] + T2.TI[i];
    }
    tab.Neff = T1.Neff;
    return tab;
}

TabInt MinusTab (TabInt T1, TabInt T2) {
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */
    // KAMUS LOKAL
    int i;
    TabInt tab;
    // ALGORITMA
    for (i = 1; i <= T1.Neff; i++) {
        tab.TI[i] = T1.TI[i] - T2.TI[i];
    }
    tab.Neff = T1.Neff;
    return tab;
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
    // KAMUS LOKAL
    // ALGORTIMA
    return T.TI[IdxMaxTab(T)];
}

ElType ValMin (TabInt T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
    // KAMUS LOKAL
    // ALGORTIMA
    return T.TI[IdxMinTab(T)];
}

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
    // KAMUS LOKAL
    int i, max = 1;
    // ALGORITMA
    for (i = 2; i <= T.Neff; i++) {
        if (T.TI[i] > T.TI[max]) {
            max = i;
        }
    }
    return max;
}

IdxType IdxMinTab (TabInt T) {
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
    // KAMUS LOKAL
    int i, min = 1;
    // ALGORITMA
    for (i = 2; i <= T.Neff; i++) {
        if (T.TI[i] < T.TI[min]) {
            min = i;
        }
    }
    return min;
}