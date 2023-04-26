/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 28 September 2022
Topik praktikum: Pasca Praktikum 4 - Array dan ADT List
Deskripsi: Implementasi arrayMhs.h
*/

#include "arrayMhs.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ARRAY ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabMhs *T) {
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
    // KAMUS LOKAL
    // ALGORITMA
    (*T).Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabMhs T) {
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl (TabMhs T) {
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
    // KAMUS LOKAL
    // ALGORITMA
    return IdxMax - IdxMin + 1;
}

IdxType GetFirstIdx (TabMhs T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
    // KAMUS LOKAL
    // ALGORITMA
    return IdxMin;
}

IdxType GetLastIdx (TabMhs T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff;
}

ElType GetElmt (TabMhs T, IdxType i) {
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
    // KAMUS LOKAL
    // ALGORITMA
    return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabMhs Tin, TabMhs *Tout) {
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
    // KAMUS LOKAL
    // ALGORITMA
    (*Tout).Neff = Tin.Neff;
    for(int i = IdxMin; i <= Tin.Neff; i++) {
        (*Tout).TI[i] = Tin.TI[i];
    }
}

void SetEl (TabMhs *T, IdxType i, ElType v) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
    // KAMUS LOKAL
    // ALGORITMA
    (*T).TI[i] = v;
    if ((*T).Neff < i) {
        (*T).Neff = i;
    }
}

void SetNeff (TabMhs *T, IdxType N) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
    // KAMUS LOKAL
    // ALGORITMA
    (*T).Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabMhs T, IdxType i) {
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
    // KAMUS LOKAL
    // ALGORITMA
    if ((i >= IdxMin) && (i <= IdxMax)){
        return true;
    } else {
        return false;
    }
}

boolean IsIdxEff (TabMhs T, IdxType i) {
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
    // KAMUS LOKAL
    // ALGORITMA
    if ((i >= IdxMin) && (i <= T.Neff)){
        return true;
    } else {
        return false;
    }
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabMhs T) {
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
    // KAMUS LOKAL
    // ALGORITMA
    if (T.Neff > 0){
        return false;
    } else {
        return true;
    }
}

/* *** Test tabel penuh *** */
boolean IsFull (TabMhs T) {
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
    // KAMUS LOKAL
    // ALGORITMA
    if (T.Neff == IdxMax){
        return true;
    } else {
        return false;
    }
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabMhs T) {
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Contoh print tabel
Test | 12321123 | 3.61
Ini Juga Test | 12321124 | 3.21
Test Lagi | 12321125 | 3.11
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
    // KAMUS LOKAL
    // ALGORITMA
    if (IsEmpty(T)) {
        printf("Tabel kosong\n");
    } else {
        for (int i = IdxMin; i <= T.Neff; i++) {
            printf("%s | %s | %.2f\n", T.TI[i].nama, T.TI[i].nim, T.TI[i].nilai);
        }
    }
}

/* ********** KONSTRUKTOR MAHASISWA ********** */
ElType MakeMahasiswa (char* Nama, char* NIM, float Nilai) {
/* Membentuk sebuah Mahasiswa dari komponen-komponennya */
/* I.S. Nama, NIM, Nilai terdefinisi */
/* F.S. Mahasiswa M terbentuk dengan Nama, NIM, Nilai yang sesuai */
    // KAMUS LOKAL
    ElType arr;
    // ALGORITMA
    arr.nama = Nama;
    arr.nim = NIM;
    arr.nilai = Nilai;
    return arr;
}

/* ********** OPERATOR STATISTIK MAHASISWA ********** */
float RataRata (TabMhs T) {
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai rata-rata dari elemen tabel */
    // KAMUS LOKAL
    float sum = 0;
    int count = 0;
    // ALGORITMA
    for (int i = IdxMin; i <= T.Neff; i++) {
        sum += T.TI[i].nilai;
        count++;
    }
    return sum/count;
}

float Max (TabMhs T) {
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai maksimum dari elemen tabel */
    // KAMUS LOKAL
    // ALGORITMA
    return T.TI[IdxMaxTab(T)].nilai;
}

float Min (TabMhs T) {
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai minimum dari elemen tabel */
    // KAMUS LOKAL
    // ALGORITMA
    return T.TI[IdxMinTab(T)].nilai;
}

char *MaxNama (TabMhs T) {
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nama mahasiswa dengan nilai tertinggi */
/* Jika ada lebih dari satu mahasiswa dengan nilai tertinggi, maka yang diambil yang nim lebih rendah */
    // KAMUS LOKAL
    int max = IdxMaxTab(T);
    // ALGORITMA
    for (int i = IdxMin; i <= T.Neff; i++) {
        if (T.TI[i].nilai == T.TI[IdxMaxTab(T)].nilai) {
            if (T.TI[i].nim < T.TI[IdxMaxTab(T)].nim) {
                max = i;
            }
        }
    }
    return T.TI[max].nama;
}

char *MinNama (TabMhs T) {
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nama mahasiswa dengan nilai terendah */
/* Jika ada lebih dari satu mahasiswa dengan nilai terendah, maka yang diambil yang nim lebih rendah */
    // KAMUS LOKAL
    int min = IdxMinTab(T);
    // ALGORITMA
    for (int i = IdxMin; i <= T.Neff; i++) {
        if (T.TI[i].nilai == T.TI[IdxMinTab(T)].nilai) {
            if (T.TI[i].nim < T.TI[IdxMinTab(T)].nim) {
                min = i;
            }
        }
    }
    return T.TI[min].nama;
}

int JumlahJurusan (TabMhs T, char* Jurusan) {
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan jumlah mahasiswa yang berasal dari jurusan Jurusan, yang berbentuk 3 angka (contoh: 182) */
/* Jika tidak ada mahasiswa yang berasal dari jurusan Jurusan, maka menghasilkan 0 */
    // KAMUS LOKAL
    int count = 0;
    // ALGORITMA
    for (int i = IdxMin; i <= T.Neff; i++) {
        if ((T.TI[i].nim[0] == Jurusan[0]) && (T.TI[i].nim[1] == Jurusan[1]) && (T.TI[i].nim[2] == Jurusan[2])) {
            count++;
        }
    }
    return count;
}

int IdxMaxTab(TabMhs T) {
// Menghasilkan indeks dengan nilai maksimum
    // KAMUS LOKAL
    int indexmax = IdxMin;
    // ALGORITMA
    for (int i = IdxMin+1; i <= T.Neff; i++) {
        if (T.TI[i].nilai > T.TI[indexmax].nilai) {
            indexmax = i;
        }
    }
    return indexmax;
}

int IdxMinTab(TabMhs T) {
// Menghasilkan indeks dengan nilai maksimum
    // KAMUS LOKAL
    int indexmin = IdxMin;
    // ALGORITMA
    for (int i = IdxMin+1; i <= T.Neff; i++) {
        if (T.TI[i].nilai < T.TI[indexmin].nilai) {
            indexmin = i;
        }
    }
    return indexmin;
}