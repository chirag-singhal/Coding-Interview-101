#include <stdio.h>
#include <stdlib.h>

// int cmpfunc (const void * a, const void * b) {
//    return ( *(int*)a - *(int*)b );
// }

int max(int a, int b){
    if(a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if(a > b)
        return a;
    else
        return b;
}

int main(){
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int n, k, sum = 0;
        scanf("%d", &n);
        scanf("%d", &k);
        int a[100000] = {0};
        int j = 0, l = n;
        while(k != 0){
            a[j] = k / l;
            // printf("%d\n", arr[j]);
            k = k - a[j];
            l--;
            j++;
        }
        for(int j = 0; j < n; j++)
            printf("%d\n", a[j]);
        // qsort(arr, n, sizeof(int), cmpfunc);

        // sum += a[n - j - 1] - a[j];
        for (int j = 0; j <= n / 2; j++)
        {
            sum += max(a[n - j - 1] - a[j] + a[n - j - 1] - a[j + 1], a[n - j -1] - a[j] + a[j] - a[n - j - 1]);
            printf("%d", sum);
        }   
    }
    return 0;
}