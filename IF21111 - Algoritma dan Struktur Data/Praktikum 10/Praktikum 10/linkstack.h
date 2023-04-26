/* File: linkstack.h */
#ifndef _LINKSTACK_H
#define _LINKSTACK_H
#include "boolean.h"
#include <stdlib.h>
#define Nil NULL

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/* Deklarasi infotype */
typedef int ElType;

/* Stack dengan representasi berkait dengan pointer */
typedef struct tNode *address;
typedef struct tNode {
    ElType Info;
    address Next;
} Node;

/* Type stack dengan ciri TOP: */
typedef struct {
    address TOP; /* alamat TOP: elemen puncak */
} Stack;

/* ********* PROTOTYPE MANAJEMEN MEMORI ********* */
void Alokasi(address *P, ElType X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/* P=Nil jika alokasi gagal */
void Dealokasi(address P);
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty(Stack S);
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmpty(Stack *S);
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
void Push(Stack *S, ElType X);
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/* jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop(Stack *S, ElType *X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/* elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */

#endif
