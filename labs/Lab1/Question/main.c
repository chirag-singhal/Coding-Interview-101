/***********file:   main.c *********/
#include <stdio.h>
#include "seqListOps.h"

int main(void)
{
 int i; int size;
 JobList list;
 size = inputJobs(list);
 printf("Size = %d\n", size);
 printf("The Jobs waiting on CPU are:\n");
 printJobList(list, size);
 sortJobList(list, size);
 printf("The Jobs after sorting are:\n");
 printJobList(list, size);
 return 0;
}
 
