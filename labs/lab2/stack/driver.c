#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char *argv[]) {
	
	if(argc < 2) {
		printf("Error provide file name!!\n");
		return 0;
	}	

	// Create a file pointer and open the file read as command line argument.
	FILE * fileptr = fopen(argv[1], "r");
	if(fileptr == NULL) {
		printf("Error opening file!!\n");
		return 0;	
	}
	// Declare a pointer to a linked list (head) and allocate memory to it.
	struct linkedList * head = (struct linkedList *) malloc (sizeof(struct linkedList));
	head -> first =  NULL;
	head -> count = 0;

	int temp = 0;		

	// In a loop read the file and insert elements into the linkedList.
	while ((fscanf(fileptr, "%d", &temp)) == 1) {
		
		// read the next element and store into the temp variable.
		
		// insert temp into the linked list.
		push(head, temp);
		printf("Element %d pushed in stack\n", temp);
	}

	// print the linked list.
	printf("\nElements in stack are - \n");
	printList(head);

	// pop all elements of stack
	NODE* ptr = pop(head);	
	while(ptr != NULL) {
		printf("Popped element = %d\n", ptr -> element);
		printList(head);
		ptr = pop(head);
	}

	// close the file pointer
	fclose(fileptr);

	return 0;
}