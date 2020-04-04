#include <stdio.h>

int count(int a, int option[]){
    // int *p = option;
    // printf("%d %d\n", a,option[0]);
    if( a < 0 || option[0] == 0 ) return 0;
    else if (a == 0) return 1;
    else return count(a, option + 1) + count(a - option[0], option);
}

int main(){
    int num, p, d;
    scanf("%d", &num);
    int choice[4] = {1, 2, 4, 0};
    // printf("%d", choice[0]);
    for (int i = 0; i < num; i++){
        scanf("%d", &p);
        scanf("%d", &d);
        int play = p - d;
        int res = count(play, choice);
        printf("%d\n", res);
    }
    return 0;
}