#include <bits/stdc++.h>

void isPrime(std::vector<bool> &A) {
    int n = A.size();
    A[0] = false, A[1] = false;
    
    for(int i = 2; i * i <= n; i++) {
        if(A[i] == true) {
            for(int j = i * i; j <=n; j += i)
                A[j] = false;
        }
    }
}

std::vector<int> primesum(int A) {
    std::vector<bool> B(A + 1, true);
    std::vector<int> ans;
    isPrime(B);
    for(int i = 2; i <= A; i++) {
        if(B[i] && B[A - i]) {
            ans.push_back(i);
            ans.push_back(A - i);
            return ans;
        }
    }
}
