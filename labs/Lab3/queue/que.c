#include "que.h"

QUEUE newQ() {
	QUEUE q = (QUEUE) malloc(sizeof(struct queue));
	q -> count = 0;
	q -> head = NULL;
	q -> tail = NULL;
	return q;
}

int isEmpty(QUEUE q) {
	if( q -> count > 0 )	return 0;
	else return 1;
}

QUEUE delQ(QUEUE q) {
	if(q -> count == 1) {
		NODE* temp = q -> head;
		q -> head = NULL;
		q -> tail = NULL;
		q -> count = 0;
		free(temp);
	}
	else if(q -> count > 1) {
		NODE* temp = q -> head;
		q -> head = temp -> next;
		q -> count --;
		free(temp);	
	}
	else {
		printf("QUEUE IS EMPTY!! CANNOT DELETE FROM EMPTY QUEUE\n");
	}
	return q;
}

ELEMENT front(QUEUE q) {
	if(q -> count > 0) {
		return q -> head -> ele;
	}
	else {
		// printf("QUEUE IS EMPTY!!\n");
		return NULL;
	}
}

QUEUE addQ(QUEUE q, ELEMENT e) {
	NODE * temp = (NODE*) malloc(sizeof(NODE));
	temp -> ele = e;
	temp -> next = NULL;
	
	if(q -> count == 0) {
		q -> head = temp;
		q -> tail = temp;
		q -> count = 1;
	}
	else {
		q -> tail -> next = temp;
		q -> tail = temp;
		q -> count ++;
	}
	
	return q;
}

int lengthQ (QUEUE q) {
	return q -> count;
}


/*
int main() {

	QUEUE q = newQ();
	printf("Is queue empty??	%s\n", isEmpty(q) ? "YES" : "NO");
	addQ(q, 1);
	addQ(q, 5);
	addQ(q, 3);
	printf("Front Element = %d\n", front(q));
	printf("Length of queue = %d\n", lengthQ(q));
	delQ(q);
	delQ(q);
	delQ(q);
	delQ(q);
	printf("Length of queue = %d\n", lengthQ(q));
	
	return 0;	
}
*/
