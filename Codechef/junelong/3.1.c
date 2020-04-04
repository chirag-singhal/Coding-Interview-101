#include <stdio.h>
#define MOD 1000000007

int main(){
    int num;
    unsigned long long int k;
    scanf("%d", &num);
    
    for(int i = 0; i < num; i++){
        scanf("%llu", &k);
        unsigned long long int res = 1;
        k = k % (MOD - 1);
        unsigned long long int y = k - 1, x = 2;
        while (y > 0) { 
        // If y is odd, multiply x with the result 
        if (y & 1) 
            res = (res * x) % MOD; 
  
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % MOD; 
    } 
        res = (res * 10) % MOD;
        printf("%llu\n", res);
    }

    return 0;
}