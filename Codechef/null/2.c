#include <stdio.h>
#define mod 1000000007

int main(){
    int num, a;
    scanf("%d", &num);

    for (int i = 0; i < num; i++){
        unsigned long long int res = 1;
        scanf("%d", &a);
        if(a % 2)
            a = a + 1;

        for(int j = a - 1; j >= 3; j -= 2){
            j = j % mod;
            res = (res * j) % mod;
            if (res == 0)
                break;
        }
        printf("%llu\n", res);
    }
    return 0;
}