#include <stdio.h>

int main(){
    int num;
    unsigned long long int choice;
    scanf("%d", &num);
    
    for(int i = 0; i < num; i++){
        scanf("%llu", &choice);
        int sum = 0,  add = 0;
        for(unsigned long long int x = choice; x > 0; x = x / 10)
            sum += x % 10;
        if(sum % 10 != 0)
            add = 10 - sum % 10;
            
        printf("%llu\n", choice * 10 + add);
       
    }

    return 0;
}