#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        long long int n, k;
        scanf("%lld", &n);
        scanf("%lld", &k);
        long int arr[n], brr[n];
        long long int l = k / n;
        l = l % 3;
        long long int p = k % n;
        for(int j = 0; j < n; j++) {
            scanf("%ld", &arr[j]);
            brr[j] = arr[j];
        }
        if(n % 2 && (k - 1) >= n / 2)
            arr[n / 2] = 0;
        for(int j = 0; j <= n; j++) {
            if(l == 0) {
                break;
            }
            else if (l == 1) {
                arr[j] = arr[j] ^ arr[n - j - 1];
            }
            else {
                arr[n - j - 1] = arr[j] ^ arr[n - j - 1];
            }
        }
        for(int j = 0; j < p; j++)
            arr[j] = arr[j] ^ arr[n - j - 1];

        // for(long long int j = 0; j < k; j++){
        //     brr[j % n] = brr[j % n] ^ brr[n - j % n - 1];
        //     printf("%ld\n", brr[j%n]);
        // }

        for(int j = 0; j < n ; j++)
            printf("%ld ", arr[j]);
        putchar('\n');
        // for(int j = 0; j < n ; j++)
        //     printf("%ld ", brr[j]);
        // putchar('\n');
    }
    return 0;
}