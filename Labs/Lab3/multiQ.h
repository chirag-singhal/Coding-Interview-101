#include "que.h"

extern MULTIQ createMQ(int num);

extern MULTIQ addMQ(MULTIQ mq, TASK t);

extern TASK nextMQ(MULTIQ mq);

extern TASK delNextMQ(MULTIQ mq);

extern int isEmptyMQ(MULTIQ mq);

extern int sizeMQ(MULTIQ mq);

extern int sizeMQbyPriority(MULTIQ mq, PRIORITY p);

extern QUEUE getQueueFromMQ(MULTIQ, PRIORITY p);
