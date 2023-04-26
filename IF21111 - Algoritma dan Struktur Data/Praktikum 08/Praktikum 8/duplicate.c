/*
Nama: Frendy Sanusi
NIM: 18221041
Tanggal: 3 November 2022
Topik praktikum: Pasca praktikum 8 - Set, Map, Hashmap
Deskripsi: Implementasi duplicate.h
*/

#include "duplicate.h"

/*
    Masukkan semua elemen array arr ke suatu Set, kemudian kembalikan Set tersebut
        Contoh:
            arrToSet
                <- arr = [1, 1, 3]
                <- arrSize = 3
            -> [1, 3]
*/
Set arrToSet(int* arr, int arrSize) {
	// KAMUS LOKAL
	int i;
	Set arrNew;
	// ALGORITMA
	CreateEmpty(&arrNew);
	for (i = 0; i < arrSize; i++) {
		Insert(&arrNew, arr[i]);
	}
	//for (i = 0; i < arrSize; i++) {
	//	cnt = 0;
	//	for (j = 0; j < arrSize; j++) {
	//		if (arr[i] == arr[j]) {
	//			cnt++;
	//		}
	//	}
		
	//	if (cnt > 1) {
	//		Insert(&arrNew, arr[i]);
	//		arrNew.Count++;
	//	}
	//}
	return arrNew;
}

/*
    Dengan memanfaatkan fungsi arrToSet, hapuslah elemen duplikat pada array arr
    kemudian kembalikan isinya secara menurun

    Penjelasan Parameter:
    Parameter 1: arr, merupakan array masukan yang perlu dihapus elemen duplikatnya
    Parameter 2: arrSize, merupakan panjang arr
    Parameter 3: arrRes, merupakan array keluaran, hasil pengapusan elemen duplikat
        dan elemen-elemennya terurut menurun
    Parameter 4: arrResSize, merupakan panjang arrRes

    Contoh: 
        removeDuplicate
            <- arr = [1, 1, 2, 3]
            <- arrSize = 4
            -> arrRes = [3, 2, 1]
            -> arrResSize = 3
        removeDuplicate
            <- arr = [3, 1, 1]
            <- arrSize = 3
            -> arrRes = [3, 1]
            -> arrResSize = 2
*/
void removeDuplicateDesc(int* arr, int arrSize, int* arrRes, int* arrResSize) {
	// KAMUS LOKAL
	int i, j, length, max, idx;
	Set arrCopy;
	// ALGORITMA
	arrCopy = arrToSet(arr, arrSize);
	*arrResSize = arrCopy.Count;
	length = *arrResSize;
	
	for (i = 0; i < length; i++) {
		arrRes[i] = arrCopy.Elements[i];
	}
	
	for (i = 0; i < length; i++) {
		max = arrRes[i];
		idx = i;
		for (j = i; j < length; j++) {
			if (arrRes[j] > max) {
				max = arrRes[j];
				idx = j;
			}
		}
		arrRes[idx] = arrRes[i];
		arrRes[i] = max;
	}
	
}
