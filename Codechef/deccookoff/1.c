#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        int arr[101] = {0};
        int max = 0;
        for(int j = 0; j < n; j++) {
            int num;
            scanf("%d", &num);
            arr[num]++;
            if(arr[num] > max)
                max = arr[num];
        }
        printf("%d\n", n - max);
    }
    return 0;
}