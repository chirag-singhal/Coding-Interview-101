/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
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
	if(sl.size > 1) {
		st[nextfreeloc].ele = j;
		int curr = sl.head;
		while(st[curr].next != -1) {
			if(curr == sl.head && compare(st[curr].ele, j) == 1) {
				st[nextfreeloc].next = sl.head;
				sl.head = nextfreeloc;
				break;
			}
			else if(compare(j, st[st[curr].next].ele) == 0 || compare(j, st[st[curr].next].ele) == 2) {
				st[nextfreeloc].next = st[curr].next;	
				st[curr].next = nextfreeloc;
				break;
			}
			else {
				curr = st[curr].next;
			}
		}
		if(st[curr].next == -1) {
			st[curr].next = nextfreeloc;
			st[nextfreeloc].next = -1;
		}
	}
	else if(sl.size == 1) {
				st[nextfreeloc].ele = j;
				if(compare(st[sl.head].ele, j) == GREATER) {
					st[nextfreeloc].next = sl.head;
					sl.head = nextfreeloc;
				}
				else {
					st[sl.head].next = nextfreeloc;
					st[nextfreeloc].next = -1;
				} 
	}
	else{
		st[sl.head].ele = j;
	}
	sl.size++;
	nextfreeloc++;
	return sl;

//Implement this function
//
 }
  
void insertelements (JobList list , int size, SeqList s[3])
{
//	for(int i = 0; i < 3; i++) {
//		s[i] = createlist();
//	}

	for(int i = 0; i < size; i++) {
		s[list[i].pri] = insert(list[i], s[list[i].pri]);
	}
// Implement this function

}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{
	int k = 0;
	for(int i = 2; i > -1; i--) {
		if(s[i].size == 0)
			continue;
		int curr = s[i].head;
		while (curr != -1) {
			printf("HELLO	");
			printJob(st[curr].ele);
			ele[k++] = st[curr].ele;
			curr = st[curr].next;
		}
	}

// Implement this function
}


void printlist(SeqList sl)
{
	printf("%d\n", sl.size);
	if(sl.size == 0)
		return;
	int curr = sl.head;
	while(curr != -1) {
		printJob(st[curr].ele);
		curr = st[curr].next;
	}

// Implement this function

}

void printJobList(JobList list, int size)
{	
	printf("SIZE = %d\n", size);
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
