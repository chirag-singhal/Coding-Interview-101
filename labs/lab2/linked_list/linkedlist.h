#include <stdio.h>
#include "node.c"

// function declarations

extern void insertFirst (struct linkedList * head, int ele);
/* inserts a given element at the beginning of the list */

extern struct node * deleteFirst(struct linkedList * head);
/* deletes the first element of the list and returns pointer to the deleted
node. */

extern void printList (struct linkedList * head);
/* prints all the elements in the list */

extern int search (struct linkedList * head, int ele);
/* searches for a given element in the linked list. Returns 1 if found, 0
otherwise. */

extern struct node * delete (struct linkedList * head, int ele);
/* delets the first node in the list that contains the element = ele and
If the element is not found it returns an error message saying
found. */
