#include <stdio.h>
#include "linkdummy.h"

int main() {
	List L; int X; address last;
	
	MakeEmpty(&L);
	//InsertFirst(&L, 5);
	InsertFirst(&L, 8);
	InsertLast(&L, 9);
	//DeleteFirst(&L, &X);
	DeleteLast(&L, &X);
	
	address p = First(L);
	printf("[");
	while (p != Last(L)) {
		printf("%d,", Info(p));
		p = Next(p);
	}
	printf("%d]\n", Info(p));
	
	last = Search(L, 8);
	printf("IsEmpty: %d\n", IsEmpty(L));
	//if (last == Nil) printf("Nil\n");
	//else printf("Info: %d\n", Info(last));
	
	return 0;
}
