#include <stdio.h>
#include "set.h"
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
    Set M1, M2, Coba; int i;

    CreateEmpty(&M1); CreateEmpty(&M2); CreateEmpty(&Coba);


    // isi HashMap
    Insert(&M1, 1);
    Insert(&M1, 2);
    Insert(&M1, 3);
   // Insert(&M, 3);
    Insert(&M2, 3);
    Insert(&M2, 2);
    Insert(&M2, 4);
    displaySet(M1); displaySet(M2);
    
    Coba = SetSubtract(M1, M2);
    displaySet(Coba);
    
    return 0;
}
