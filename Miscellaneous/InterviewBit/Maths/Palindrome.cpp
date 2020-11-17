#include <bits/stdc++.h>

int isPalindrome(int A) {
    if(A < 0)
        return 0;
    int rev  = 0;
    int n = A;
    while(n != 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev == A;
}
