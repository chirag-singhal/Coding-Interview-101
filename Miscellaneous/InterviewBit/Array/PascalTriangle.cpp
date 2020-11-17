#include <bits/stdc++.h>

std::vector<std::vector<int> > solve(int A) {
    std::vector<std::vector<int>> ans;
    for(int i = 0; i < A; i++) {
        std::vector<int> a1;
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) {
                a1.push_back(1);
            }
            else 
                a1.push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
        }
        ans.push_back(a1);
    }
    return ans;
}
