#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct student {
	char name[20];
	float cgpa;
} STUDENT;

typedef STUDENT Element;

int* endmem;

extern int min(int n1, int n2);

extern void readData(FILE* f, Element Ls[], int n);

extern void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);

extern void mergeSort(Element Ls[], int n);
