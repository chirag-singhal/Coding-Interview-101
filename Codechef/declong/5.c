#include <stdio.h>

int main() {
    long int t;
    scanf("%ld", &t);
    for (long int i = 0; i < t; i++) {
        long int n;
        long long int two = 0;
        long long int zero = 0;
        unsigned long long int ans = 0;
        scanf("%ld", &n);
        for(int j = 0; j < n;  j++) {
            long long int num;
            scanf("%lld", &num);
            if(num == 2)
                two++;
            if(num == 0)
                zero++;
        }
        ans = two * (two - 1);
        ans = ans / 2;
        ans =  ans + (zero * (zero - 1))/2;
        printf("%llu\n", ans);
    }
    
    return 0;
}