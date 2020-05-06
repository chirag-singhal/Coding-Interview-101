#include <bits/stdc++.h>

int hammingDistance(const std::vector<int> &A) {
    int count  = 0;
    for(int i = 0; i < 31; i++) {
        int n_one = 0;
        for(int j = 0; j < A.size(); j++) {
            if(A[j] & (1 << i))
                n_one++;
        }
        count = count % 1000000007 + (2 * (n_one) * (A.size() - n_one)) % 1000000007;
        count = count % 1000000007;
    }
    return count;
}
