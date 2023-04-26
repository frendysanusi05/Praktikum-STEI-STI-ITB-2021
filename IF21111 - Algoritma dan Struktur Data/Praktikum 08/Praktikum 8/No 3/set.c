/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 31 Oktober 2022
Topik praktikum: Praktikum 8 - Set, Map, Hashmap
Deskripsi: Implementasi set.h
*/

#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
    S->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return S.Count == Nil;
}

boolean IsFull(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    return S.Count == MaxEl;
}

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (IsMember(*S, Elmt))
    {
        return;
    }
    S->Elements[S->Count] = Elmt;
    S->Count++;
}

void Delete(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    boolean found = false;
    address idx = 0, iterator;
    if (!IsMember(*S, Elmt))
    {
        return;
    }
    while (!found && idx < S->Count)
    {
        if (S->Elements[idx] == Elmt)
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    for (iterator = idx + 1; iterator < S->Count; iterator++)
    {
        S->Elements[iterator - 1] = S->Elements[iterator];
    }
    S->Count--;
}

boolean IsMember(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    boolean found = false;
    address idx = 0, iterator;
    while (!found && idx < S.Count)
    {
        if (S.Elements[idx] == Elmt)
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    return found;
}

Set SetUnion(Set s1, Set s2) {
// Mengembalikan set baru yang berisi elemen-elemen yang terdapat pada s1 atau s2
// Contoh: [1, 2] U [2, 3] = [1, 2, 3]
	// KAMUS LOKAL
	int i, length1 = s1.Count, length2 = s2.Count;
	Set UnionSet;
	// ALGORITMA
	CreateEmpty(&UnionSet);
	for (i = 0; i < length1; i++) {
		Insert(&UnionSet, s1.Elements[i]);
	}
	
	for (i = 0; i < length2; i++) {
		Insert(&UnionSet, s2.Elements[i]);
	}
	return UnionSet;
}

Set SetIntersection(Set s1, Set s2) {
// Mengembalikan set baru yang berisi elemen-elemen dari s1 dan s2 yang terdapat pada kedua set
// Contoh: [1, 2] ∩ [2, 3] = [2]
	// KAMUS LOKAL
	int i, j;
	Set Intersect;
	// ALGORITMA
	CreateEmpty(&Intersect);
	
	for (i = 0; i < s1.Count; i++) {
		for (j = 0; j < s2.Count; j++) {
			if (s1.Elements[i] == s2.Elements[j]) {
				Insert(&Intersect, s1.Elements[i]);
			}
		}
	}
	return Intersect;
}

Set SetSymmetricDifference(Set s1, Set s2) {
// Mengembalikan set baru yang berisi elemen yang ada di s1 atau s2, tapi tidak pada keduanya
// Contoh: [1, 2] ⊖ [2, 3] = [1, 3]
	// KAMUS LOKAL
	int i, j, cnt = 0;
	Set sym;
	// ALGORITMA
	CreateEmpty(&sym);
	
	for (i = 0; i < s1.Count; i++) {
		cnt = 0;
		for (j = 0; j < s2.Count; j++) {
			if (s1.Elements[i] == s2.Elements[j]) {
				cnt++;
			}
		}
		if (cnt == 0) {
			Insert(&sym, s1.Elements[i]);
		}
	}
	
	for (i = 0; i < s2.Count; i++) {
		cnt = 0;
		for (j = 0; j < s1.Count; j++) {
			if (s2.Elements[i] == s1.Elements[j]) {
				cnt++;
			}
		}
		if (cnt == 0) {
			Insert(&sym, s2.Elements[i]);
		}
	}	
	return sym;
}

Set SetSubtract(Set s1, Set s2) {
// Mengembalikan set baru yang berupa hasil pengurangan s1 dengan s2
// Contoh:
// s1 = [1, 2] s2 = [2, 3]
// s1 - s2 = [1]
	// KAMUS LOKAL
	Set subtract;
	int i, j, cnt;
	// ALGORITMA
	CreateEmpty(&subtract);
	for (i = 0; i < s1.Count; i++) {
		cnt = 0;
		for (j = 0; j < s2.Count; j++) {
			if (s1.Elements[i] == s2.Elements[j]) {
				cnt++;
			}
		}
		if (cnt == 0) {
			Insert(&subtract, s1.Elements[i]);
		}
	}
	return subtract;
}
