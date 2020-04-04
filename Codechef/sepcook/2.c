#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        long int a, b, c;
        scanf("%ld %ld %ld", &a, &b, &c);
        long int ans = a + 2 * b + 3 * c;
        // printf("%ld\n", ans);
        if(ans % 2)
            printf("%s\n", "NO");
        else {
            ans /= 2;
            if(ans <= a + 2 * b)
                printf("%s\n", "YES");
            else
            {
                
            }
            
        }
    }
    return 0;
}