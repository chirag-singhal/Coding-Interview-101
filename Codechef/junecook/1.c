#include <stdio.h>

int main(){
    int test, num;
    char key[101], sol[101];
    scanf("%d", &test);
    for(int i = 0; i < test; i++){
        int score = 0;
        scanf("%d", &num);
        scanf("%s", sol);
        scanf("%s", key);
        for(int j = 0; j < num; j++){
            if(sol[j] == key[j])
                score += 1;
            else if(key[j] == 'N')
                continue;
            else
                j++;
        }
        printf("%d\n", score);
    }
    return 0;
}