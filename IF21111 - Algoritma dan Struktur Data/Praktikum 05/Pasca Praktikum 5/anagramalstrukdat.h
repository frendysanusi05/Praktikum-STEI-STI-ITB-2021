#include "mesinkarakterv2.h"
#include "mesinkata.h"
#include "boolean.h"

#ifndef ANAGRAMALSTRUKDAT_H
#define ANAGRAMALSTRUKDAT_H

/*  Menerima sebuah parameter string bertipe string
    Mengirimkan panjang sebuah string */
int stringLength (char* string);

/*  Menerima sebuah paramater command bertipe string
    Mengirimkan kata yang elemen of arraynya berasal dari command */
Word toKata(char* command);

/*  Menerima dua buah parameter yaitu string1 dan string2
    Mengembalikan true apabila string2 merupakan anagram dari string1
    Mengembalikan false apabila string2 bukan merupakan anagram dari string1
    String dianggap anagram apabila disusun dari huruf yang tepat sama */
boolean isAnagram(Word string1, Word string2);

/*  Mengembalikan jumlah frekuensi kemunculan anagram alstrukdat 
    pada argumen frek */
void anagramalstrukdat(int* frek);


#endif