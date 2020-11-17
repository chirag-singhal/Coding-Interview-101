#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        int n, m;
        scanf("%d", &n);
        scanf("%d", &m);

        if(m < n - 1 || m > n * (n + 1) / 2)
            printf("%d\n", -1);
        else {
            
        }
    }
}