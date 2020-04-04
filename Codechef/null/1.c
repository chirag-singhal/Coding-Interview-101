#include <stdio.h>
int main(){
    int num, a, b;
    scanf("%d", &num);

    for (int i = 0; i < num; i++){
        scanf("%d", &a);
        scanf("%d", &b);
        printf("%d ", a + b -1);
        if(a > b)
            printf("%d\n", a - b + 1);
        else
            printf("%d\n", b - a + 1);
    }
    return 0;
}