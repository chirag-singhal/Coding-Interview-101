#include <stdio.h>
#include "linkedlist.h"

void insertFirst(struct linkedList * head, int ele){
	//create a node
	NODE* link = (NODE *) malloc (sizeof(NODE));

	/* by this you are creating a node whose address is being stored in the link pointer. */
	link->element = ele;
	//point it to old first node
	link->next = head->first;

	//point first to new first node
	head -> first = link;
	head -> count ++;
}

//delete first item
NODE* deleteFirst(struct linkedList * head) {
	if(head -> count > 0) {
		// exercise to implement this operation.
		NODE* temp = head -> first;
		head -> first = temp -> next;
		head -> count --;
		return temp;
	}
	return NULL;
}

//display the list
void printList(struct linkedList * head){
	NODE* ptr = head->first;
	printf("[ ");
	//start from the beginning
	while(ptr != NULL){
		printf("%d, ", ptr->element);
		ptr = ptr->next;
	}
	printf(" ]\n\n");
}

//search element = ele in linked list
int search(struct linkedList *head, int ele) {
	NODE* ptr = head -> first;
	while(ptr != NULL) {
		if(ele == ptr -> element)
			return 1;
		ptr = ptr -> next;
	}
	return 0;
}

/* delets the first node in the list that contains the element = ele and
If the element is not found it returns an error message saying
found. */
struct node* delete (struct linkedList * head, int ele) {
	if(head -> count > 0) {
		NODE* ptr = head -> first;
		if(ele == ptr -> element) {
			head -> first = ptr -> next;
			return ptr;	
		}
		while(ptr -> next != NULL) {
			if(ele == ptr -> next -> element) {
				NODE* temp = ptr -> next;			
				ptr -> next = temp -> next;
				head -> count --;				
				return temp;
			}
			ptr = ptr -> next;
		}
	}
	
	return NULL;
}

