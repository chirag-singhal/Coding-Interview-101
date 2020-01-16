#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

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
		insertFirst(head, temp);
	}

	// close the file pointer
	

	// print the linked list.
	printList(head);
	
	// delete the first element of the linked list.
	deleteFirst(head);
	
	// print the linked list again to check if delete was successful.
	printList(head);

	// print the linked list to a new file.
	if(argc > 2) {
		fseek(fileptr, 0, SEEK_SET);
		FILE * fwrite = fopen(argv[2], "w");
		if(fwrite == NULL) {
			printf("Error opening file!!\n");
			return 0;
		}
		while (!feof(fileptr)) {
		
			// read the next element and store into the temp variable.
			int temp;
			fscanf(fileptr, "%d", &temp);

			// write temp into fwrite
			fprintf(fwrite, "%d ", temp);
		}
		printf("\nSuccessfully printed in the file!!\n");
		fclose(fwrite);
			
	}
	fclose(fileptr);
	//search element = ele in linked list
	int ele;	
	printf("\nEnter element to be searched = ");
	scanf("%d", &ele);
	if(search(head, ele))
		printf("FOUND!!!\n");
	else 
		printf("NOT FOUND!!!\n");
	
	//delete element = ele in linked list
	printf("Enter element to be deleted = ");
	scanf("%d", &ele);
	if(delete(head, ele) == NULL)
		printf("ELEMENT NOT FOUND!!!\n");

	printList(head);
	puts("\n");
	

	return 0;
}
