#include <stdio.h>

int main(){
    int test;
    scanf("%d", &test);
    for(int i = 0; i < test; i++){
        int n, m, d, v, smallest;
        int ad[2] = {0, 0};
        int av[2] = {0, 0};
        scanf("%d", &n);
        scanf("%d", &m);
        for(int j = 0; j < n; j++){
            int sameday = 0;
            scanf("%d", &d);
            scanf("%d", &v);
            for(int k = 0; k < 2; k++){
                if(d == ad[k]){
                    sameday = 1;
                    if(v > av[k]){
                        ad[k] = d;
                        av[k] = v;
                        break;
                    }
                }
            }
            if(!sameday){
                if(av[0] < av[1])
                    smallest = 0;
                else
                    smallest = 1;
                if(v > av[smallest]){
                    av[smallest] = v;
                    ad[smallest] = d;
                }
            }
        }
        printf("%d\n", av[0] + av[1]);
    }
    return 0;
}