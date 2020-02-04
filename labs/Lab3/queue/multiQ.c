#include "multiQ.h"
#define NUM 10

MULTIQ createMQ(int num) {
	MULTIQ mq = (MULTIQ) malloc(num * sizeof(QUEUE));
	for(int i = 0; i < num; i++)
		mq[i] = newQ();
	
	return mq;
}

MULTIQ addMQ(MULTIQ mq, TASK t) {
	addQ(mq[t -> prior - 1], t);
	return mq;
}

TASK nextMQ(MULTIQ mq) {
	TASK t = NULL;
	int num = sizeof(mq) / sizeof(mq[0]) - 1;
	for(int i = NUM - 1; i >= 0; i--) {
		t = front(mq[i]);
		if(t != NULL)
			break;
	}
	return t;
}

TASK delNextMQ(MULTIQ mq) {
	TASK t = NULL;
	for(int i = NUM - 1; i >= 0; i--) {
		t = front(mq[i]);
		if(t != NULL){
			delQ(mq[i]);
			break;
		}
	}
	return t;
}

int isEmptyMQ(MULTIQ mq) {
	for(int i = 0; i < NUM; i++)
		if(!isEmpty(mq[i]))
			return 0;
	return 1;
}

int sizeMQ(MULTIQ mq) {
	int size = 0;
	for(int i = 0; i < NUM; i++)
		size += lengthQ(mq[i]);
	return size;
}

int sizeMQbyPriority(MULTIQ mq, PRIORITY p) {
	return lengthQ(mq[p - 1]);
}

QUEUE getQueueFromMQ(MULTIQ mq, PRIORITY p) {
	return mq[p -1];
}
