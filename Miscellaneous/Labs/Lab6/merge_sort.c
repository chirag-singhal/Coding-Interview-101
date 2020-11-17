#include "merge_sort.h"

void readData(FILE* f, Element Ls[], int n) {
	for(int i = 0; i < n; i++) {
		fscanf(f, "%[^,], %f\n", Ls[i].name, &Ls[i].cgpa);
		//printf("%s, %f\n", Ls[i].name, Ls[i].cgpa); 	
	}
	//putchar('\n');
}

int min(int n1, int n2) {
	if(n1 < n2)
		return n1;
	return n2;
}

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]) {
	int i = 0, j = 0, k = 0;
	while(i < sz1 && j < sz2) {
		if(Ls1[i].cgpa < Ls2[j].cgpa)
			Ls[k++] = Ls1[i++];
		else 
			Ls[k++] = Ls2[j++];	
	} 
	
	while(i < sz1) 
		Ls[k++] = Ls1[i++];

	while(j < sz2) 
		Ls[k++] = Ls2[j++];
}	

int main() {
	int num[] = {1024, 10240};
	char file[2][12] = {"1024.txt", "10240.txt"};
	for(int i = 0; i < 2; i++) {
		FILE* f = fopen(file[i], "r");
		if(f == NULL) 
			printf("Error!! Can't open the file.\n");	
		else {
			Element Ls[num[i]];
			readData(f, Ls, num[i]);
			struct timeval  start, end;
			gettimeofday(&start, NULL);
			int startmem;
			mergeSort(Ls, num[i]);	
			gettimeofday(&end,NULL);
			double time_taken = (end.tv_sec - start.tv_sec) * 1000;
			time_taken += ((double)end.tv_usec - start.tv_usec) / 1000;
			printf("Time taken for sorting %d elements = %lfms\n", num[i], time_taken);
			printf("Space used for sorting %d elements = %ld\n", num[i], (long)&startmem - (long)endmem);	
		}		
	}
	return 0;
}
