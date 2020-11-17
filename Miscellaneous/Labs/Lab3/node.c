#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

//defining node and queue structure

typedef int PRIORITY;

struct task {
	int taskID;
	PRIORITY prior;
};

typedef struct task* TASK;

typedef TASK ELEMENT;

typedef struct node {
	ELEMENT ele;
	struct node* next;
} NODE;

struct queue {
	NODE* head;
	NODE* tail;
	int count;
};


typedef struct queue* QUEUE;


typedef QUEUE* MULTIQ; 
