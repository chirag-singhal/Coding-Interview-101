#include <stdio.h>

int main() {
    int t;
    int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        int a;
        int b;
        scanf("%d %d", &a, &b);
        long int ans = a + b;
        long long int count = 0;
        for(long int i = ans; ans != 0; ans /= 10){
            count += arr[ans % 10];
            // printf("%lld\n", count);
        }
        printf("%lld\n", count);
    }
    return 0;
}