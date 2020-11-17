#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

typedef struct employee {
	char name[20];
	int empID;
} EMPLOYEE;

typedef EMPLOYEE Element;

extern void readData(FILE* f, Element Ls[], int n);

extern int partition(Element Ls[], int lo, int hi);

extern void quickSort(Element Ls[], int lo, int hi, int s);

extern void exchange(Element Ls[], int i, int j);

extern void insertionSort(Element Ls[], int n);

extern void sort(Element Ls[], int n, int s);

extern double* testRun(Element Ls[], int n);

extern int estimateCutoff(Element Ls[], int n);