#include <stdio.h>
#include <stdlib.h>

long int max(long int a, long int b) {
    if(a > b)
        return a;
    return b;
}

long int min(long int a, long int b) {
    if(a > b)
        return b;
    return a;
}

int main() {
    long int t;
    scanf("%ld", &t);
    for (long int i = 0; i < t; i++) {
        long int n;
        scanf("%ld", &n);
        char arr[n+1];
        scanf("%s", arr);
        int brr[26] = {0};
        long int result = 0;
    
        // for (long int k=1; k<=n; k++) { 
        //     for (long int j=1; j<=n; j++) {
        //         if (arr[k-1] == arr[j-1] && k != j) { 
        //             result = max(result, min(k, j) + n -  max(k, j)); 
        //             // printf("%ld %ld %ld\n", k, j, result);
        //         } 
        //     } 
        // }
        long int mins = n; 
        for(int j = 1; j <= n; j++) {
            int ch = arr[j - 1] - 'a';
            if(brr[ch] > 0)
                mins = min(mins, j - brr[ch]);
            brr[ch] = j;
        }
        result = n - mins;

        // for(long int k = 0; k<=n; k++) {
        //     for(long int j = 0; j<=n; j++)
        //         printf("%ld  ", LCSuff[k][j]);
        //     putchar('\n');
        // }
        printf("%ld\n", result);
    }
    
    return 0;
}