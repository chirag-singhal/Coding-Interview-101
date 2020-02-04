#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

typedef int ELEMENT;

typedef struct node {
	ELEMENT ele;
	struct node* next;
} NODE;

struct linkedlist {
	int count;
	NODE* head;
	NODE* tail;
};

typedef struct linkedlist* LinkedList;

extern void myfree(void* ptr, int size);

extern void* myalloc(int size);

extern void printUsedHeap(); 