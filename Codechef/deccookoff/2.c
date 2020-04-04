#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        char arr[1001];
        int brr[1000] = {0};
        int k = 0;
        scanf("%s", arr);
        int n = strlen(arr);
        char ch = arr[0];
        for(int j = 0; j < n; j++) {
            if(arr[j] == ch)
                brr[k]++;
            else {
                k++;
                brr[k]++;
                ch = arr[j];
            }
        }
        // for(int j = 0; j < k + 1; j++) 
            // printf("%d ", brr[j]);
        // putchar('\n');
        int curr = k + 1;
        int ans = 0;
        int sum = brr[0] + brr[k];
        int found = 0;
        if(curr < 4) 
            printf("%d\n", 0);
        else {
            for(int l = 0; l < k + 1; l++) {
                int min = 2000;
                int index = 0;
                for(int j = 1; j < k; j++) {
                    if(brr[j] == 0) continue;
                    if(brr[j] < min && index != 0) {
                        min = brr[j];
                        index = j;
                    }
                }
                if(sum > brr[index]) {
                    brr[index] = 0;
                    brr[index - 1] = brr[index - 1] + brr[index + 1];
                    brr[index + 1] = 0;
                    ans += min;
                    curr -= 2;
                    // printf("%d\n", 2);
                }
                else if(!found && sum < brr[index]) {
                    ans += sum;
                    curr -= 2;
                    found = 1;
                    // printf("%d\n", 3);
                }
                else if(found && sum < brr[index]) {
                    brr[index] = 0;
                    brr[index - 1] = brr[index - 1] + brr[index + 1];
                    brr[index + 1] = 0;
                    ans += min;
                    curr -= 2;
                    // printf("%d\n", 4);
                }
                // printf("%d %d %d %d\n", min, index, curr, ans);
                if(curr < 4)
                    break;
            }
        }
        // for(int j = 0; j < k + 1; j++) 
            // printf("%d ", brr[j]);
        // putchar('\n');
        printf("%d\n", ans);
    }
    return 0;
}