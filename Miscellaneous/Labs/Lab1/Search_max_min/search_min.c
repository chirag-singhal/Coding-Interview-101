

int search(int arr[], int n) {
	
	if(n > 0) {
		int min = arr[0];
		for(int i = 0; i < n; i++)
			if(min > arr[i])
				min = arr[i];

		printf("In function min = %d\n", min);
		return min;
	}
	return -1;
}
