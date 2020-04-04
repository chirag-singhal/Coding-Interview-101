#include <stdio.h>

int main(){
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int n, steal = 0, found = 0;
        double mean = 0;
        scanf("%d", &n);
        long long int coins[n];

        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &coins[j]);
            mean += coins[j];
        }
        mean = mean / n;
        for (int j = 0; j < n; j++){
            if(!found && coins[j] == mean){
                // printf("First found %d", j + 1);
                found = j + 1;
                break;
            }
        }
        if(!found)
            printf("Impossible\n");
        else
            printf("%d\n", found);
            
    }
    return 0;
}