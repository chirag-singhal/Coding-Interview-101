#include <stdio.h>
#include <math.h>
#define MOD 1000000007

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        long long int A, B, C;
        long long int count = 0;
        scanf("%lld", &A);
        scanf("%lld", &B);
        scanf("%lld", &C);

        for(long long int a = 2; a <= A; a++){
            if(a > B * B + 1) {
                count = ( count + ((A - a + 1) * (C - 1) * B) % MOD) % MOD;
                break;
            }
            for(long long int c = 2; c <= C; c++)
            {
                if(c > B * B + 1 && a > 1) {
                    count = ( count + ((C - c + 1) * B) % MOD) % MOD;
                    break;
                }
                if((a - 1) * (c -1) <= B * B)
                    if((int)sqrt((a - 1) * (c - 1)) == sqrt((a - 1) * (c - 1)) && (int)sqrt((a - 1) * (c - 1)) > 0)
                        count = ( count + (int)sqrt((a - 1) * (c - 1)) - 1) % MOD;
                    else
                        count = ( count + (int)sqrt((a - 1) * (c - 1))) % MOD;
                else
                    count = (count + B) % MOD;
                // printf("%lld\n", count);
            }
        }



        printf("%lld\n", count);
    }
    return 0;
}