#include <stdio.h>

void mergesort(int a[], int i, int j);
void merge(int a[], int i1, int j1, int i2, int j2);
unsigned long long int nCr (int n, int r);

int main()
{
    int count = 0;
    int n, i, k, t, b = 0;
    scanf("%d", &t);
    for (int l = 0; l < t; l++)
    {
        // printf("Enter no of elements:");
        scanf("%d", &n);
        int a[n];
        scanf("%d", &k);
        // printf("Enter array elements:");

        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);

        mergesort(a, 0, n - 1);

        // printf("\nSorted array is :");
        // for (i = 0; i < n; i++)
        //     printf("%d\n", a[i]);
        for (int i = 0; i < n; i++)
        {
            if( i > k - 1)
                count++;
            if(a[k - 1] == a[i])
                b++;
            else break;
        }
        printf("%llu\n", nCr(b, b - count));
    }
    return 0;
}
unsigned long long int nCr (int n, int r) {
    unsigned long long int res = 1;
    int k = r >= (float)n / 2 ? n - r : r;
    int i , j;
    for(i = n, j = 1; i > n - k, j <= k; i--,j++){
        res = (res * i )/ j;
    }
    return res;
}
void mergesort(int a[], int i, int j)
{
    int mid;

    if (i < j)
    {
        mid = (i + j) / 2;
        mergesort(a, i, mid);         //left recursion
        mergesort(a, mid + 1, j);     //right recursion
        merge(a, i, mid, mid + 1, j); //merging of two sorted sub-arrays
    }
}

void merge(int a[], int i1, int j1, int i2, int j2)
{
    int temp[50]; //array used for merging
    int i, j, k;
    i = i1; //beginning of the first list
    j = i2; //beginning of the second list
    k = 0;

    while (i <= j1 && j <= j2) //while elements in both lists
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= j1) //copy remaining elements of the first list
        temp[k++] = a[i++];

    while (j <= j2) //copy remaining elements of the second list
        temp[k++] = a[j++];

    //Transfer elements from temp[] back to a[]
    for (i = i1, j = 0; i <= j2; i++, j++)
        a[i] = temp[j];
}