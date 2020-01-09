/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.size = 0;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}

SeqList findnextfreeLoc(SeqList sl) {
	sl.head = nextfreeloc;
	st[sl.head].next = -1;
	return sl;
}

void rightShift(int size, int j) {
	for(int i = j; i < j + size; j++)
		st[i + 1] = st[i];
}

int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{	
	if(sl.size > 0) {
		int i = 0;
		for(i = sl.head; i < sl.head + sl.size; i++) {
			if(compare(st[i].ele, j)) {
				rightShift(sl.size, i);
				st[i].ele = j;
				st[i].next = i + 1;
				printf("HEAD1\n");
				break;
			}
		}
		if(i == sl.head + sl.size) {
			st[i].ele = j;
			st[i].next = -1;
			st[i - 1].next = i;
			printf("HEAD2\n");
		}
	}
	else{
		sl = findnextfreeLoc(sl);
		st[sl.head].ele = j;
		printf("HEAD3\n");
	}
	sl.size++;
	nextfreeloc++;
	return sl;
//Implement this function
//
 }
  
void insertelements (JobList list , int size, SeqList s[3])
{
	for(int j = 2; j > -1; j--) {
		for(int i = 0; i < size; i++) {
			if(list[i].pri == j)
				s[j] = insert(list[i], s[j]);
		}
	}
// Implement this function

}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{
	for(int i = 0; i < s[0].size + s[1].size + s[2].size; i++)
		ele[i] = st[i].ele;

// Implement this function
}


void printlist(SeqList sl)
{
	if(sl.size == 0)
		return;
	int curr = sl.head;
	for(int i = sl.head; i < sl.head + sl.size; i++) 
		printJob(st[i].ele);

// Implement this function
}

void printJobList(JobList list, int size)
{	
	for(int i = 0; i < size; i++)
		printJob(list[i]);

// Implement this function

}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);
 printf("SEQ 0\n");
 printlist(seq[0]);   
 printf("SEQ 1\n");
 printlist(seq[1]);
 printf("SEQ 2\n");
 printlist(seq[2]);
 copy_sorted_ele (seq , list); 
}
