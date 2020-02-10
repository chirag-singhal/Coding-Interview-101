/***********file:   job.h *********/
#define MAX 10

typedef enum {PRI_0, PRI_1, PRI_2} Priority;
typedef int Job_Id;
typedef int ExecutionTime;
typedef int ArrivalTime;

typedef struct
{
 Job_Id id;
 Priority pri;
 ExecutionTime et;
 ArrivalTime at;
} Job;

typedef Job JobList[MAX];

