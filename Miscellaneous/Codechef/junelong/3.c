#include <stdio.h>
#include <math.h>

int main(){
    int num;
    unsigned long long int k;
    scanf("%d", &num);
    
    for(int i = 0; i < num; i++){
        scanf("%llu", &k);
        int total = 0;
        
        for(int j = 0; j < pow(10, k); j++){
            int number[10] = {0};
            int count = 0;

            if(j == 0 || j == pow(10, k) - 1 && number[0] == 0){
                number[0]++;
                count++;
            }

            for(int x = j; x > 0; x = x / 10){
                int divi = x % 10;
                if( number[divi] == 0){
                    number[divi]++;
                    count++;
                }
            }
            for(int x = pow(10, k) - j - 1; x > 0; x = x / 10){
                int divi = x % 10;
                if( number[divi] == 0){
                    number[divi]++;
                    count++;
                }
            }
            if(count == 2){
                total++;
                // printf("%d  %d\n", j, (int)pow(10, k) - j - 1);
            }
        }

        printf("%d\n", total);
       
    }

    return 0;
}