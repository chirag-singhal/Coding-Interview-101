#include <stdio.h>

int count(int num, int a, int b, int tot[]) {
    if( num < 0 || a > b ) return 0;
    else if( num == 0) return 1;
    else{
        return count(num, a + 1, b, tot) + count(num - a, a, b, tot);
    }
}


int main() {
    int n, a, b, c, d;
    int t[b - a];
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    printf("%d\n", count(n,a,b, t));

    return 0;
    
}