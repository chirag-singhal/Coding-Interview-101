#include "merge_sort.h"

void mergeSort(Element Ls[], int n) {
	for(int i = 1; i < n; i *= 2) {
		for(int j = 0; j < n; j += 2 * i) {
			if(j + 2 * i > n)
				continue;
			int sz1 = i, sz2 = min(i, n - j);
			Element Ls1[sz1], Ls2[sz2], Ls3[sz1 + sz2];
			for(int k = 0; k < i; k++)
				Ls1[k] = Ls[j + k];
			for(int k = 0; k < sz2; k++)
				Ls2[k] = Ls[j + i + k];

			merge(Ls1, sz1, Ls2, sz2, Ls3);

			for(int k = 0; k < sz1 + sz2; k++)
				Ls[j + k] = Ls3[k];

			int end;
			endmem = &end;
		}
	}
}
