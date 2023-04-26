/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 31 Oktober 2022
Topik praktikum: Praktikum 8 - Set, Map, Hashmap
Deskripsi: Implementasi union_map.h
*/

#include "union_map.h"

Map UnionMap(Map m1, Map m2, boolean key_based ) {
    /* Menggabungkan m1 dengan m2 pada sebuah map baru dengan urutan yang ditentukan berdasarkan key_based
    apabila key_based true maka elemen dalam map baru ditambahkan mengurut membesar berdasarkan keynya
    apabila key_based false maka elemen dalam map baru ditambahkan mengurut membesar berdasarkan valuenya*/

    /*I.S : Map m1 dan m2 terdefinisi. m1 dan m2 TIDAK kosong dan TIDAK penuh
    F.S : Map m3 yang merupakan gabungan isi dari m1 dan m2 yang diisi berdasarkan nilai key_based. Jumlah elemen m3 TIDAK mungkin melebihi MaxEl*/

    /*Notes: 
        1. Apabila terdapat nilai key yg sama pada m1 dan m2, value yang akan ditambah pada map baru adalah value dari m1 pada key tersebut
        2. Ingat yang unik adalah key, bukan value
    Hint: Lakukan penambahan semua elemen dari m1 dan m2 ke m3 terlebih dahulu kemudian urutkan isinya menggunakan algoritma sorting*/
    
    /*
    Contoh:
        1.Input(format <key,value>):
            m1: {<7,1>,<1,2>,<20,3>}
            m2: {<8,100>,<11,10>}
            key_based: true
          Output:
            m3: {<1,2>,<7,1>,<8,100>,<11,10>,<20,3>}
        2.Input(format <key,value>):
            m1: {<7,1>,<1,2>,<20,3>}
            m2: {<8,100>,<11,10>}
            key_based: false
          Output:
            m3: {<7,1>,<1,2>,<20,3>,<11,10>,<8,100>}
    */

	// KAMUS LOKAL
	Map UnionMap;
	int i, j, idx;
	infotype min, temp;
	boolean kunci = key_based;
	// ALGORITMA
	CreateEmpty(&UnionMap);
	
	for (i = 0; i < m1.Count; i++) {
		Insert(&UnionMap, m1.Elements[i].Key, m1.Elements[i].Value);
	}
	
	for (i = 0; i < m2.Count; i++) {
		Insert(&UnionMap, m2.Elements[i].Key, m2.Elements[i].Value);
	}

	if (kunci) {
		for(i = 0; i < UnionMap.Count-1; i++) {
            for(j = 0; j < UnionMap.Count-i-1; j++) {
                if (UnionMap.Elements[j].Key > UnionMap.Elements[j+1].Key) {
                    
                    temp.Key = UnionMap.Elements[j].Key;
                    temp.Value = UnionMap.Elements[j].Value;
                    UnionMap.Elements[j].Key = UnionMap.Elements[j+1].Key;
                    UnionMap.Elements[j].Value = UnionMap.Elements[j+1].Value;
                    UnionMap.Elements[j+1].Key = temp.Key;
                    UnionMap.Elements[j+1].Value = temp.Value;
                }
            }
        }
	} else {
		for (i = 0; i < UnionMap.Count-1; i++) {
            for (j = 0;j < UnionMap.Count-i-1;j++) {
                if (UnionMap.Elements[j].Value > UnionMap.Elements[j+1].Value) {
                    temp.Key = UnionMap.Elements[j].Key;
                    temp.Value = UnionMap.Elements[j].Value;
                    UnionMap.Elements[j].Key = UnionMap.Elements[j+1].Key;
                    UnionMap.Elements[j].Value = UnionMap.Elements[j+1].Value;
                    UnionMap.Elements[j+1].Key = temp.Key;
                    UnionMap.Elements[j+1].Value = temp.Value;
                }
            }
        }
	}

	// if (kunci) {
	// 	for (i = 0; i < UnionMap.Count; i++) {
	// 		min = UnionMap.Elements[i];
	// 		idx = i;
	// 		for (j = i; j < UnionMap.Count; j++) {
	// 			if (UnionMap.Elements[j].Key < min.Key) {
	// 				min = UnionMap.Elements[j];
	// 				idx = j;
	// 			}
	// 		}
	// 		UnionMap.Elements[idx] = UnionMap.Elements[i];
	// 		UnionMap.Elements[i] = min;
	// 	}
	// } else {
	// 	for (i = 0; i < UnionMap.Count; i++) {
	// 		min = UnionMap.Elements[i];
	// 		idx = i;
	// 		for (j = i; j < UnionMap.Count; j++) {
	// 			if (UnionMap.Elements[j].Value < min.Value) {
	// 				min = UnionMap.Elements[j];
	// 				idx = j;
	// 			}
	// 		}
	// 		UnionMap.Elements[idx] = UnionMap.Elements[i];
	// 		UnionMap.Elements[i] = min;
	// 	}
	// }
	
	return UnionMap;
}