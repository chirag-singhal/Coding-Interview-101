#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        long int n, m, q, row, col;
        long long int count = 0, od1 = 0, od2 = 0;
        scanf("%ld", &n);
        scanf("%ld", &m);
        scanf("%ld", &q);
        // int *r = malloc(n * sizeof(int));
        // int *c = malloc(m * sizeof(int));
        long int r[100000] = {0}; 
        long int c[100000] = {0}; 
        // int* rc = malloc(n * m * sizeof(int));
        // for(long int j = 0; j < n; j++)
        //     r[j] = 0;
        // for(long int k = 0; k < m; k++)
        //     c[k] = 0;
        // for(int j = 0; j < n; j++)
        //     for(int k = 0; k < m; k++) 
        //         rc[j * m + k] = 0;
        for(long int j = 0; j < q; j++) {
            scanf("%ld", &row);
            scanf("%ld", &col);
            if(r[row - 1] % 2)
                od1--;
            else
                od1++;
            if(c[col - 1] % 2)
                od2--;
            else 
                od2++;
            r[row - 1]++;
            c[col - 1]++;
            // rc[(row - 1) * m + col - 1]++;
        }
        // for(int j = 0; j < n; j++)
        //     printf("%ld  ", r[j]);
        // putchar('\n');
        // for(int k = 0; k < m; k++)
        //     printf("%ld  ", c[k]);
        // putchar('\n');
        // for(int j = 0; j < n; j++) {
        //     for(int k = 0; k < m; k++) 
        //         printf("%ld  ", rc[j * m + k]);
        //     putchar('\n');
        // }
        // for(long int j = 0; j < n; j++){
        //     for(long int k = 0; k < m; k++){ 
        //         // printf("%ld %ld %ld\n", r[j], r[k], r[j] + r[k]);
        //         if((r[j] + c[k]) % 2)
        //             count++;
        //     }
        // }
        count = od1 * (m - od2) + od2 * (n - od1);
        printf("%lld\n", count);
    }
    return 0;
}