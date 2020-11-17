#include<bits/stdc++.h>

int mod(int x) {
    if (x < 0)
        return -x;
    return x;
}

int coverPoints(std::vector<int> &A, std::vector<int> &B) {
    int n = A.size();
    int count = 0;
    for(int i = 0; i < n - 1; i++) {
        int xDiff = mod(A[i + 1] - A[i]);
        int yDiff = mod(B[i + 1] - B[i]);
        if(xDiff < yDiff)
            count += yDiff;
        else
            count += xDiff;
    }
    return count;
}
