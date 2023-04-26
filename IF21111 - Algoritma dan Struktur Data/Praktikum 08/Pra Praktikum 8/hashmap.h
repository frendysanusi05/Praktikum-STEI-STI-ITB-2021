#ifndef hashHashMap_H
#define hashHashMap_H
#include <stdio.h>
#include "boolean.h"

/**
 * Modul Hash HashMap
 * Implementasi Hash HashMap dengan Open Addressing
*/

// #define false 0
// #define true 1
#define Nil 0
#define MaxEl 16
#define Undefined -9999

// typedef int bool;
typedef int keytype;
typedef int valuetype;
typedef int address;

typedef struct
{
	keytype Key;
	valuetype Value;
} infotype;

typedef struct
{
	infotype Elements[MaxEl];
	address Count;
} HashMap;

/* Definisi HashMap M kosong : M.Count = Nil */
/* M.Count = jumlah element HashMap */
/* M.Elements = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi map Undefined */

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K);
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(HashMap *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing jika index sudah terisi    */

#endif