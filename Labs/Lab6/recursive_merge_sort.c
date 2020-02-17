#include "merge_sort.h"

void recursiveMergeSort(Element Ls[], int lo, int hi) {
	if(lo >= hi) {
		int end;
		endmem = &end;
		return;
	}
	
	int mid = lo + (hi - lo) / 2;

	int sz1 = mid - lo + 1;
	int sz2 = hi - mid;
	Element Ls1[sz1], Ls2[sz2], Ls3[sz1 + sz2];

	recursiveMergeSort(Ls, lo, mid);
	recursiveMergeSort(Ls, mid + 1, hi);	

	for(int i = 0; i < sz1; i++)
		Ls1[i] = Ls[lo + i];
	for(int i = 0; i < sz2; i++)
		Ls2[i] = Ls[mid + 1 + i];

	merge(Ls1, sz1, Ls2, sz2, Ls3);

	for(int i = 0; i < sz1 + sz2; i++)
		Ls[lo + i] = Ls3[i];
}

void mergeSort(Element Ls[], int n) {
	recursiveMergeSort(Ls, 0, n - 1);
}
