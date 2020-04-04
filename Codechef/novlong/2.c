#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        int n;
        int arr[10] = {0};
        scanf("%d", &n);
        for(int k = 0; k < n; k++) {
            char ch[10];
            getchar();
            scanf("%s", ch);
            for(int j = 0; j < 10; j++) {
                // printf("%c %d\n", ch, j);
                if(ch[j] == '1'){
                    // printf("    %d  %d\n", j, arr[j]);
                    arr[j]++;
                }
            }
        }
        int count = 0;
        // for(int k = 0; k < 10; k++)
            // printf("%d\n", arr[k]);
        for(int k = 0; k < 10; k++)
            if(arr[k] % 2)
                count++;
        printf("%d\n", count);
    }
    return 0;
}