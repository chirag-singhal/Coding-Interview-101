#include "cycle.h"

LinkedList createList(int n) {
	srand(time(0));
	LinkedList ls = (LinkedList) malloc(sizeof(struct linkedlist));
	ls -> head = NULL;
	ls -> tail = NULL;
	ls -> count = 0;
	if(n < 1)
		return ls;
	else {
		NODE* temp = (NODE*) myalloc(sizeof(NODE));
		temp -> ele = rand();
		temp -> next = NULL;
		ls -> head = temp;
		ls -> tail = temp;
		ls -> count = 1;
	}			
	for(int i = 1; i < n; i++) {
		NODE* temp = (NODE*) myalloc(sizeof(NODE));
		temp -> ele = rand();
		temp -> next = NULL;
		ls -> tail -> next = temp;
		ls -> tail = temp;
		ls -> count++;
		
	}
	return ls;
}

LinkedList createCycle(LinkedList ls) {
	int coin = rand() % 2;
	printf("Coin = %d\n", coin);	
	if(coin) {
		int r = rand() % (ls -> count);
		int i = 0;
		NODE* temp = ls -> head;
		for(int i = 0; i < r; i++)
			temp = temp -> next;
		ls -> tail -> next = temp;
	}
	return ls;
}

LinkedList makeCyclic(LinkedList ls, int ifCyclic) {
	if(ls -> count < 1)
		return ls;
	else if(ifCyclic == 0){
		ls -> tail -> next = ls -> head;
	}
	else {
		NODE* temp = ls -> head;
		while(temp != ls -> tail -> next) {
			NODE* next = temp -> next;
			myfree(temp, sizeof(NODE));
			temp = next;
		}
		ls -> head = temp;
	}
	return ls;
}


int main() {
	struct timeval start, end;
	double elapsedTime;
	gettimeofday(&start, NULL);
	LinkedList ls = createList(100000);
	createCycle(ls);
	int ifCyclic = testCyclic(ls);
	if(ifCyclic)
		printf("LinkedList is cyclic\n");
	else 
		printf("LinkedList is Linear\n");
	
	gettimeofday(&end, NULL);
	elapsedTime = (end.tv_sec - start.tv_sec) * 1000.0;
	elapsedTime += (end.tv_usec - start.tv_usec) / 1000.0;
	printUsedHeap();
	printf("Time for running %lf ms\n", elapsedTime);
	return 0;	
}
