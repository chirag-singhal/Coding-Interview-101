#include <bits/stdc++.h>

int sqrt(int A) {
    int lo = 1;
    int hi = A;
    while(lo <= hi) {
        long int mid = ((long)lo + (long)hi) / 2;
        if(mid * mid == A)
            return mid;
        else if(mid * mid > A)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return lo - 1;
}
