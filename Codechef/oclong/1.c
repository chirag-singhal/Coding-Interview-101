#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, temp;
        int i = 0, count = 0;
        int arr[5];
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            int min = 0;
            scanf("%d", &temp);
            if(j == 0) {
                count++;
            }
            else if(j < 5) {
                min = arr[0];
                for(int k = 0; k < i; k++)
                    if(arr[k] < min)
                        min = arr[k];
                if(temp < min)
                    count++;
            }
            else {
                min = arr[0];
                for(int k = 0; k < 5; k++)
                    if(arr[k] < min)
                        min = arr[k];
                if(temp < min)
                    count++;
            }
            arr[i] = temp;
            i = ( i + 1 ) % 5;
        }
        printf("%d\n", count);
    }
    return 0;
}