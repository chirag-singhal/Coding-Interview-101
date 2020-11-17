#include <stdio.h>
#include <string.h>
int main() {
    long int t;
    scanf("%ld", &t);
    for (long int i = 0; i < t; i++) {
        unsigned long long int a, b;
        a = b = 0;
        int k = 0;
        char arr[100001], brr[100001];
        scanf("%s", arr);
        scanf("%s", brr);
        int alen = strlen(arr);
        int blen = strlen(brr);
        char ch = arr[0]; 
        while(ch != '\0') {
            ch = arr[k];
            if(ch == '1') {
                unsigned long long int pow = 1;
                for(int j = 0; j < alen - k - 1; j++) {
                    pow *= 2;
                }
                a += pow;
                // printf("%llu\n", a);
            }
            k++;
        }
        k = 0;
        ch = brr[0];
        while(ch != '\0') {
            ch = brr[k];
            if(ch == '1') {
                unsigned long long int pow = 1;
                for(int j = 0; j < blen - k - 1; j++) {
                    pow *= 2;
                }
                b += pow;
                // printf("%llu\n", b);
            }
            k++;
        }
        // printf("%llu %llu\n", a, b);
        unsigned long long int ans, u, v;
        ans = 0;
        while(b > 0) {
            u = a^b;
            v = a&b;
            a = u;
            b = v * 2;
            ans++;
            // printf("%llu %llu %llu %llu\n", u, v, a, b);
        }
        printf("%llu\n", ans);
    }
    
    return 0;
}