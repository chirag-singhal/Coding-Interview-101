#include <stdio.h>

int main(){
    int num, size;
    char atten[1001];
    scanf("%d", &num);
    
    for(int i = 0; i < num; i++){
        int count = 0;
        int proxy = 0;
        scanf("%d", &size);
        scanf("%s", atten);
        for(int j = 0; j < size; j++)
            if(atten[j] == 'P')
                count++;

            if(count < 0.75 * size)
                for(int i = 2; i < size - 2; i++){
                    if(atten[i] == 'A' && (atten[i-1] == 'P' || atten[i - 2] == 'P') && (atten[i + 1] == 'P' || atten[i + 2] == 'P'))
                        proxy++;
                    if(proxy + count >= 0.75 * size){
                        printf("%d\n", proxy);
                        break;
                    }
                }
            else if(count >= 0.75 * size)
                printf("%d\n", proxy);
                
            if(proxy + count < 0.75 * size)
                        printf("-1\n");
    }
}