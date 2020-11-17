#include <bits/stdc++.h>

int solve(std::vector<int> &A) {
    int n = A.size();
    std::sort(A.begin(), A.end());
    for(int i = 0; i < n - 1; i++) {
        if(A[i] != A[i + 1]) {
            if(A[i] == n - i - 1)
                return 1;
        }
    }
    if(A[n - 1] == 0)
        return 1;
    else 
        return -1;
}
