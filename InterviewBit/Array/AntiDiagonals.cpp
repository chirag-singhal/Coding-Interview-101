#include <bits/stdc++.h>

std::vector<std::vector<int> > diagonal(std::vector<std::vector<int> > &A) {
    std::vector<std::vector<int>> ans;
    int r = 0, c = 0;
    for(int i = 0; i < 2 * A.size() - 1; i++) {
        int l = r, m = c;
        if(c < A.size() - 1)
            c++;
        else 
            r++;
        std::vector<int> a1;
        while(l < A.size() && m >= 0) {
            a1.push_back(A[l][m]);
            l++;
            m--;
        }
        ans.push_back(a1);
    }
    return ans;
}
