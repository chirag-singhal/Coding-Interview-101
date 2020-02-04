#include "dynalloc.h"

unsigned long long int spacealloc = 0;

void myfree(void* ptr, int size) {
	spacealloc -= size;
	// printf("Space allocated = %lld\n", spacealloc);
	free(ptr);
}

void* myalloc(int size) {
	spacealloc += size;
	//printf("Space allocated = %lld\n", spacealloc);
	return malloc(size);	
}

void printUsedHeap() {
	printf("Size of used heap = %llu bytes\n", spacealloc);
}

/*
int main() {
	int m = 0;
	srand(time(0));
	for(int i = 0; i < 1; i++){
		m = rand() % ( 15001 ) + 10000;
		int* arr = (int*) myalloc(m * sizeof(int));
		printf("FIRST ADD -> %u		LAST ADD -> %u\n", arr, &arr[m - 1]);
		//myfree(arr, sizeof(int) * m);
	}
	return 0;
}
*/
