#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    int arr[128] = {0};
    arr[1] = 0;
    int brr[128] = {0};
    for(int i = 2; i < 128; i++) {
        for(int j = i - 2; j > -1; j--) {
            if(arr[i - 1] == arr[j]){
                arr[i] = i - 1 - j;
                break;
            }
        }
    }
    // for(int i = 0; i < 128; i++)
    //     printf("%d  %d\n", arr[i], arr[i]);
    for(int i = 0; i < t; i++) {
        int n, count = 0;
        scanf("%d", &n);
        for(int j = 0; j < n; j++)
            if(arr[j] == arr[n - 1])
                count++;
        printf("%d\n", count);
    }
    return 0;
}