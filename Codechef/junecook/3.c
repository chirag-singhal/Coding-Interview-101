#include <stdio.h>

int main(){
    int cas;
    scanf("%d", &cas);
    for (int i = 0; i < cas; i++) {
        int n, m, avail[100000], fav, order[100000] = {0};
        long long int pricefav, priceother, profit = 0;
        scanf("%d", &n);
        scanf("%d", &m);
        for(int j = 0; j < m; j++)
            scanf("%d", &avail[j]);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &fav);
            scanf("%lld", &pricefav);
            scanf("%lld", &priceother);
            if(avail[fav - 1] > 0){
                avail[fav - 1]--;
                profit += pricefav;
                order[j] = fav;
            }
            else {
                profit += priceother;
            }
        }
        for(int j = 0; j < n; j++){
            if(order[j] != 0)
                continue;
            else
                for (int k = 0; k < n; k++)
                    if(avail[k] > 0){
                        order[j] = k + 1;
                        avail[k]--;
                        break;
                    }
        }
        printf("%lld\n", profit);
        for(int j = 0; j < n; j++)
            printf("%d ", order[j]);
        printf("\n");
    }
    
    return 0;
}