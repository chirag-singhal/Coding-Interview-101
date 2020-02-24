#include "quick_sort.h"

void readData(FILE* f, Element Ls[], int n) {
	for(int i = 0; i < n; i++) {
		fscanf(f, "%s %d\n", Ls[i].name, &Ls[i].empID);
		//printf("%s, %f\n", Ls[i].name, Ls[i].cgpa); 	
	}
	//putchar('\n');
}

void exchange(Element Ls[], int i, int j) {
    Element temp = Ls[i];
    Ls[i] = Ls[j];
    Ls[j] = temp; 
}

int partition(Element Ls[], int lo, int hi) {
	int p = Ls[hi].empID;
    int i = lo - 1;
    for(int j = lo; j < hi; j++) {
        if(Ls[j].empID <= p) {
            i++;
            exchange(Ls, i, j);
        }
    }
    exchange(Ls, i + 1, hi);
    return i + 1;
}	

void insertionSort(Element Ls[], int n) {
    for(int i = 1; i < n; i++) {
        Element temp = Ls[i];
        int j = i - 1;
        while(j >= 0 && Ls[j].empID > temp.empID) {
            Ls[j + 1] = Ls[j];
            j = j - 1;
        }
        Ls[j + 1] = temp;
    }
}

void quickSort(Element Ls[], int lo, int hi, int s) {
    int sk[hi - lo + 1]; 
    int top = -1; 
    sk[++top] = lo; 
    sk[++top] = hi; 

    while (top >= 0) { 
        hi = sk[top--]; 
        lo = sk[top--]; 
        int p = partition(Ls, lo, hi); 
        if (p - lo > s) { 
            sk[++top] = lo; 
            sk[++top] = p - 1; 
        } 
        if (hi - p > s) { 
            sk[++top] = p + 1; 
            sk[++top] = hi; 
        } 
    } 
}

void sort(Element Ls[], int n, int s) {
    quickSort(Ls, 0, n - 1, s);
    insertionSort(Ls, n);
    // for(int i = 0; i < n; i++) {
    //     printf("%d\n", Ls[i].empID);
    // }
}

double* testRun(Element Ls[], int n) {
    Element Ls1[n], Ls2[n];
    for(int i = 0; i < n; i++) {
        Ls1[i] = Ls[i];
        Ls2[i] = Ls[i];
    }
    double* time_taken = (double *) malloc(2 * sizeof(double));
    struct timeval  start, end;
	gettimeofday(&start, NULL);
	quickSort(Ls1, 0, n - 1, 0);	
	gettimeofday(&end,NULL);
	time_taken[1] = (end.tv_sec - start.tv_sec) * 1000;
	time_taken[1] += ((double)end.tv_usec - start.tv_usec) / 1000;

    gettimeofday(&start, NULL);
	insertionSort(Ls2, n);	
	gettimeofday(&end,NULL);
	time_taken[0] = (end.tv_sec - start.tv_sec) * 1000;
	time_taken[0] += ((double)end.tv_usec - start.tv_usec) / 1000;
    // printf("T %Lf\n", time_taken[0]);

    return time_taken;
}

int estimateCutoff(Element Ls[], int n) {
    int min = 20;
    int max = n;
    double* tt;
    int mid;
    double* tt1 = testRun(Ls, min);
    // printf("%Lf %Lf\n", tt1[0], tt1[1]);
    if(tt1[0] > tt1[1])
        printf("QuickSort is faster\n");
    double* tt2 = testRun(Ls, max);
    // printf("%Lf %Lf\n", tt2[0], tt2[1]);
    if(tt2[1] > tt2[0])
        printf("InsertionSort is faster\n");

    do {
        mid = (min + max) / 2;
        tt = testRun(Ls, mid);
        if(tt[0] > tt[1])
            max = mid;
        else 
            min = mid;
        // printf("Time %d %d %d %Lf %Lf\n", max, mid, min, tt[0], tt[1]);
    } while(tt[0] + 0.01 > tt[1] && min != max);
    return mid;
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Filename not provided\n");
    }
    else {
        char filename[20];
        strcpy(filename, argv[1]);
        int num = atoll(filename);
        FILE* f = fopen(filename, "r");
        if(f == NULL) 
            printf("Error!! Can't open the file.\n");	
        else {
            Element Ls[num];
            readData(f, Ls, num);
            int mid = estimateCutoff(Ls, num);
            struct timeval  start, end;
            gettimeofday(&start, NULL);
            sort(Ls, num, mid);
            gettimeofday(&end,NULL);
            double time_taken = (end.tv_sec - start.tv_sec) * 1000;
            time_taken += ((double)end.tv_usec - start.tv_usec) / 1000;
            // printf("%d\n", mid);
            printf("Time taken for sorting %d elements = %lfms\n", num, time_taken);
        }
	}		
	return 0;
}
