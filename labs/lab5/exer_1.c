#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>

typedef struct credit_card {
	long long int card_number;
	char bank_code[6];
	char expiry_date[8];
	char first_name[30];
	char last_name[30];
} CREDIT_CARD;

typedef struct credit_card* CREDIT_CARDS;

struct records {
	CREDIT_CARDS credit_cards;
	long int size;
	long int capacity;
};

typedef struct records* RECORDS;

RECORDS read_cards(RECORDS re, int N, FILE* f) {
	int size = re -> size;
	int capacity = re -> capacity;
	CREDIT_CARDS cred_card = re -> credit_cards;
	for(int i = size; i < size + N; i++) {
		if(i + 1 > capacity) {
			capacity *= 2;
			cred_card = (CREDIT_CARDS) realloc(cred_card, sizeof(struct credit_card) * capacity);
		}			
		char arr[60];
		char card_number[30];
		fscanf(f, "\"%lld,%[^,],%[^,],%[^,],%[^\"]\"", 
			&cred_card[i].card_number,
			cred_card[i].bank_code, 
			cred_card[i].expiry_date, 
			cred_card[i].first_name, 
			cred_card[i].last_name);
		fgetc(f);	
		re -> size ++;
	
		/* 
			scanf(f, "%[^\n]", arr);
			printf("%s", arr);
			strncpy(card_number, arr + 1, 16);
			cred_card[i].card_number = atoll(card_number);
			strncpy(cred_card[i].bank_code, arr + 18, 5);
			strncpy(cred_card[i].expiry_date, arr + 24, 7);
			int j = 32, k = 0;	
			while(arr[j]!= ',')
				cred_card[i].first_name[k++] = arr[j++];
			k = 0;
			j++;
			cred_card[i].first_name[k] = '\0';
			while(arr[j] != '"')
			cred_card[i].last_name[k++] = arr[j++];
			cred_card[i].last_name[k] = '\0';	 		 	
			fgetc(f);
		*/		
		}
	
	re -> credit_cards = cred_card;
	return re;
}

void insertInOrder(CREDIT_CARDS cc, long int i) {
	CREDIT_CARD key = cc[i];
	long int j = i - 1;
	while(j >= 0 && cc[j].card_number > key.card_number) {
		cc[j + 1] = cc[j];
		j--;
	}
	cc[j + 1] = key;
}

long long int insertionSort(CREDIT_CARDS cc, long int size, int* startmem) {
		if(size == 1){
			int endmem;;
			return startmem - &endmem;
		}
		long long int mem = insertionSort(cc, size - 1, startmem);
		insertInOrder(cc, size - 1);
		return mem;
}

int main() {
	
	char filename[10] = "10000";
	char file[5][10] = {"10", "100", "1000", "10000", "100000"};
	FILE* f = fopen(filename, "r");
	FILE* fout = fopen("output.txt", "w");
	FILE* foutsort = fopen("output_sort.txt", "w");
	if(f == NULL || fout == NULL || foutsort == NULL) {
		printf("Unable to open file\n");
		return 0;
	}
	for(int i = 0; i < 4; i++) {
		struct timeval start, end;
		gettimeofday(&start, NULL);
		double time_elapsed;
		RECORDS r = (RECORDS) malloc(sizeof(struct records));
		r -> credit_cards = (CREDIT_CARDS)  malloc(sizeof(struct credit_card) * 1000);
		r -> size = 0;
		r -> capacity = 1000;
		r = read_cards(r, atoi(filename), f);
		for(int j = 1; j < pow(10, i); j++){
			r = read_cards(r, atoi(filename), f);
		}
		gettimeofday(&end, NULL);
		time_elapsed = (end.tv_sec - start.tv_sec) * 1000;
		time_elapsed += (end.tv_usec - start.tv_usec) / 1000;
		// printf("%ld\n", r -> size);
		fprintf(fout, "%ld, %lfms\n", r -> size, time_elapsed);
		fseek(f, 0, SEEK_SET);
	}
	for(int i = 0; i < 5; i++) {
		FILE* fr = fopen(file[i], "r");
		struct timeval start, end;
		double time_elapsed;
		RECORDS r = (RECORDS) malloc(sizeof(struct records));
		r -> credit_cards = (CREDIT_CARDS)  malloc(sizeof(struct credit_card) * 1000);
		r -> size = 0;
		r -> capacity = 1000;
		r = read_cards(r, atoi(file[i]), fr);
		int startmem;
		gettimeofday(&start, NULL);
		long long int stackmem = insertionSort(r -> credit_cards, r -> size, &startmem);
		gettimeofday(&end, NULL);
		time_elapsed = (end.tv_sec - start.tv_sec) * 1000;
		time_elapsed += (end.tv_usec - start.tv_usec) / 1000;
		// printf("%ld\n", r -> size);
		fprintf(foutsort, "%ld, %lfms, %lld\n", r -> size, time_elapsed, stackmem);
		fclose(fr);
	}
	fclose(f);
	fclose(foutsort);
	fclose(fout);
	return 0;
}


