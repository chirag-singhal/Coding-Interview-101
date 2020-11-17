#include <bits/stdc++.h>

std::vector<int> findPerm(const std::string A, int B) {
    std::vector<int> ans;
    for(int i = 0; i < B; i++)
        ans.push_back(i + 1);
    std::stack<int> s;
    int k = 0;
    for(int i = 0; i < B - 1; i++) {
        if(A[i] == 'I') {
            s.push(i + 1);
            while(!s.empty()) {
                ans[k++] = s.top();
                s.pop();
            }
        }
        else 
            s.push(i + 1);
    }
    s.push(B);
    while(!s.empty()) {
        ans[k++] = s.top();
        s.pop();
    }
    return ans;
}
