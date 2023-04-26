#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
    M->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
    return M.Count == Nil;
}

boolean IsFull(Map M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
{
    return M.Count == MaxEl;
}

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k)
/* Mengembalikan nilai value dengan key k dari M */
{
    boolean found = false;
    address idx = 0, iterator;

    while (!found && idx < M.Count) {
        if (M.Elements[idx].Key == k) {
            found = true;
        }
        else {
            idx++;
        }
    }

    return M.Elements[idx].Value;
}

void Insert(Map *M, keytype k, valuetype v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (IsMember(*M, k)) {
        return;
    }

    M->Elements[M->Count].Key = k;
    M->Elements[M->Count].Value = v;
    M->Count++;
}

void Delete(Map *M, keytype k)
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    boolean found = false;
    address idx = 0, iterator;

    if (!IsMember(*M, k)) {
        return;
    }

    while (!found && (idx < M->Count)) {
        if (M->Elements[idx].Key == k) {
            found = true;
        }
        else {
            idx++;
        }
    }

    for (iterator = (idx + 1); iterator < M->Count; iterator++) {
        M->Elements[iterator - 1].Key = M->Elements[iterator].Key;
        M->Elements[iterator - 1].Value = M->Elements[iterator].Value;
    }

    M->Count--;
}

boolean IsMember(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    boolean found = false;
    address idx = 0, iterator;

    while (!found && idx < M.Count) {
        if (M.Elements[idx].Key == k) {
            found = true;
        }
        else {
            idx++;
        }
    }

    return found;
}
