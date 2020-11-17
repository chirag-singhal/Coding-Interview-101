

int search(int arr[], int n) {
	if( n > 0) {
		int max = arr[0];
		for(int i = 0; i < n; i++)
			if(max < arr[i])
				max = arr[i];
		
		printf("In function max = %d\n", max);
		return max;
	}
	return -1;
}
