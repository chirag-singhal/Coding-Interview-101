#include <stdio.h>

int main() {
	int num;
	FILE *fptr;
	fptr = fopen ("program.txt", "r");
	if (fptr == NULL){
		printf("Error! opening file\n");
		// Program exits if the file pointer returns NULL.
		return 0;
	}
	fscanf(fptr,"%d",&num);
	printf("Value of n=%d\n",num);
	fclose(fptr);
	
	return 0;
}
