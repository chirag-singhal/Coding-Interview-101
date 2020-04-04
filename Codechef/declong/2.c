#include <stdio.h>

int main() {
    long int t;
    scanf("%ld", &t);
    for (long int i = 0; i < t; i++) {
        long int n;
        scanf("%ld", &n);
        int arr[8] = {0};
        int answer = 0;
        for(int j = 0; j < n; j++) {
            int ques, score;
            scanf("%d", &ques);
            scanf("%d", &score);
            if(ques > 8)
                continue;
            if(arr[ques - 1] < score) {
                answer = answer - arr[ques - 1] + score;
                arr[ques - 1] = score;
            }
        }
        printf("%d\n", answer);
    }
    
    return 0;
}