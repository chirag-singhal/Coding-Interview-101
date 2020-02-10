#include <stdio.h>
#include "search.h"

int main() {
	int a[] = {2, 4, 3, 1, 5, 9, 8, 10};
	int ele = search(a, 8);
	printf("In function main , element = %d\n", ele);

	return 0;
}
