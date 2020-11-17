#include <stdio.h>

int main(int argc, char* argv[]) {

	if(argc < 3) {
		printf("Error provide two file names!!!\n");	
		return 0;	
	}
	
	FILE* fread = fopen(argv[1], "r");
	FILE* fwrite = fopen(argv[2], "w");
	
	if(fread == NULL || fopen == NULL) {
		printf("Error opening file!!!\n");	
		return 0;
	}
	char str[30];
	while(fgets(str, 30, fread) != NULL)
		fputs(str, fwrite);
	printf("File contents copied!!\n");	
	fclose(fread);
	fclose(fwrite);
	return 0;

}
