#include <bits/stdc++.h>

std::vector<int> getRow(int A) {
    std::vector<int> ans;
    int k = 1;
    for(int i = 1; i <= A + 1; i++) {
        ans.push_back(k);
        k = (k * (A + 1 - i)) / i;
    }
    return ans;
}
