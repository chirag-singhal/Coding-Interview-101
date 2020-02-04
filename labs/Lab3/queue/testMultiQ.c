#include "multiQ.h"

MULTIQ loadData(FILE* f);

void testDel(MULTIQ mq, int num);

int main(int argc, char* argv[]) {
	if(argc < 2) {
		printf("Error!! File name not specified\n");
	}
	else {
		FILE* fptr = fopen(argv[1], "r");
		if(fptr == NULL)
			printf("Error!! Can't open file\n");
		else {
			struct timeval start, end;
			double elapsedTime;
			gettimeofday(&start, NULL);
			MULTIQ mq = loadData(fptr);
			gettimeofday(&end, NULL);
			elapsedTime = (end.tv_sec - start.tv_sec) * 1000.0;
			elapsedTime += (end.tv_usec - start.tv_usec) / 1000.0;
			printf("Time for loading the date %lf ms\n", elapsedTime);
			gettimeofday(&start, NULL);
			testDel(mq, 10);
			gettimeofday(&end, NULL);
			elapsedTime = (end.tv_sec - start.tv_sec) * 1000.0;
			elapsedTime += (end.tv_usec - start.tv_usec) / 1000.0;
			printf("Time for testdel operation %lf ms\n", elapsedTime);
			printf("Average Time for testdel operation %lf ms\n", elapsedTime / 10);
		}
	}
	
	return 0;
}

MULTIQ loadData(FILE* f) {
	int taskID, prior;
	MULTIQ mq = createMQ(10);
	while(fscanf(f, "%d, %d", &taskID, &prior) == 2) {
		TASK t = (TASK) malloc(sizeof(struct task));
		t -> taskID = taskID;
		t -> prior = prior;
		addMQ(mq, t);
	}
	return mq;
}

void testDel(MULTIQ mq, int num) {
	for(int i = 0; i < num; i++)
		if(delNextMQ(mq) == NULL)
			printf("MULTI QUEUE IS EMPTY!!\n");

}
	
