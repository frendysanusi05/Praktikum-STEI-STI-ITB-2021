#include <stdio.h>
#include "duplicate.h"
//#include "hashmap.h"

//void displayHashMap(HashMap M) {
    // display HashMap
 //   int i;

  //  printf("Key: [");
  //  for (i = 0; i < MaxEl; i++) {
  //      if (i == MaxEl-1) {
   //         printf("%d]\n", M.Elements[i].Key);
  //      } else {
   //         printf("%d, ", M.Elements[i].Key);
   //     }
  //  }

  //  printf("Value: [");
  //  for (i = 0; i < MaxEl; i++) {
   //     if (i == MaxEl-1) {
  //          printf("%d]\n", M.Elements[i].Value);
  //      } else {
   //         printf("%d, ", M.Elements[i].Value);
   //     }
   // }
//}

void displaySet(Set S) {
	int i;
	
	printf("Set:[");
	for (i = 0; i < S.Count; i++) {
		if (i == S.Count-1) {
            printf("%d]\n", S.Elements[i]);
        } else {
            printf("%d, ", S.Elements[i]);
        }
	}
}

int main() {
    Set M; int i;

    CreateEmpty(&M);
    
    M.Count = 4;
    M.Elements[0] = 1;
    M.Elements[1] = 1;
    M.Elements[2] = 2;
    M.Elements[3] = 3;
   // M.Elements[4] = 4;
    

    // isi HashMap
    //Insert(&M, 1);
    //Insert(&M, 2);
    //Insert(&M, 3);
   // Insert(&M, 3);
  //  Insert(&M, 3);
  //  Insert(&M, 2);
   // Insert(&M, 4);
    displaySet(M);
    // printf("CountAwal: %d\n", M.Count);
    
    int* arr = M.Elements;
    int arrSize = M.Count;
    
    //M = arrToSet(arr, arrSize);
    //displaySet(M);
    //printf("Count: %d\n", M.Count);
    
    int* arrRes;
    int arrResSize;
    removeDuplicateDesc(arr, arrSize, arrRes, &arrResSize);
    printf("arrResSize: %d\n", arrResSize);
   
	for (i = 0; i < arrResSize; i++) {
		printf("%d\n", arrRes[i]);
	}

    //printf("Count: %d\n", M.Count);

    // printf("Value: %d\n", Value(M, 40));
    // printf("Value: %d\n", Value(M, 56));
    return 0;
}
