/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 16 September 2022
Topik praktikum: Pra Praktikum 3 - ADT, Pointer, Array Dinamik
Deskripsi: Implementasi point.h
*/

#include <stdio.h>
#include <math.h>
#include "point.h"

double square (double number) {
    // KAMUS LOKAL
    // ALGORITMA
    return number * number;
}

POINT MakePOINT (float X, float Y) {
/* Membentuk sebuah POINT dari komponen-komponennya */
    // KAMUS LOKAL
    POINT P;
    // ALGORITMA
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P) {
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    // KAMUS LOKAL
    float X, Y;
    // ALGORITMA
    scanf("%f %f", &X, &Y);
    *P = MakePOINT(X, Y);
}

void TulisPOINT (POINT P) {
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
    // KAMUS LOKAL
    // ALGORITMA
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    // KAMUS LOKAL
    // ALGORITMA
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    // KAMUS LOKAL
    // ALGORITMA
    return (!EQ(P1, P2));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P) {
/* Menghasilkan true jika P adalah titik origin */
    // KAMUS LOKAL
    // ALGORITMA
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P) {
/* Menghasilkan true jika P terletak Pada sumbu X */
    // KAMUS LOKAL
    // ALGORITMA
    return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P) {
/* Menghasilkan true jika P terletak pada sumbu Y */
    // KAMUS LOKAL
    // ALGORITMA
    return (Absis(P) == 0);
}

int Kuadran (POINT P) {
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
    // KAMUS LOKAL
    // ALGORITMA
    if ((Absis(P) > 0) && (Ordinat(P) > 0)) {
        return 1;
    } else if ((Absis(P) < 0) && (Ordinat(P) > 0)) {
        return 2;
    } else if ((Absis(P) < 0) && (Ordinat(P) < 0)) {
        return 3;
    } else if ((Absis(P) > 0) && (Ordinat(P) < 0)) {
        return 4;
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT PlusDelta (POINT P, float deltaX, float deltaY) {
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    // KAMUS LOKAL
    // ALGORITMA
    return MakePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY);
}

void Geser (POINT *P, float deltaX, float deltaY) {
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    // KAMUS LOKAL
    // ALGORITMA
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

float Jarak0 (POINT P) {
/* Menghitung jarak P ke (0,0) */
    // KAMUS LOKAL
    // ALGORITMA
    return sqrt(square(Absis(P) - 0) + square(Ordinat(P) - 0));
}

float Panjang (POINT P1, POINT P2) {
/* Menghitung panjang garis yang dibentuk P1 dan P2. */
    // KAMUS LOKAL
    // ALGORITMA
    return sqrt(square(Absis(P1) - Absis(P2)) + square(Ordinat(P1) - Ordinat(P2)));
}