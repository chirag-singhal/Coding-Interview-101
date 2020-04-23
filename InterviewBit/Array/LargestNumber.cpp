#include <bits/stdc++.h>

int comparator(int a, int b) {
    std::string s1 = std::to_string(a);
    std::string s2 = std::to_string(b);
    
    std::string x = s1 + s2;
    std::string y = s2 + s1;
    
    if(x.compare(y) > 0)
        return 1;
    return 0;
}

std::string largestNumber(const std::vector<int> &A) {
    std::string ans;
    std::vector<int> B = A;
    std::sort(B.begin(), B.end(), comparator);
    for(int i = 0; i < B.size(); i++) {
        if(B[i] == 0)
            continue;
        ans += std::to_string(B[i]);
    }
    if(ans.compare("") == 0)
        ans += "0";
    return ans;
}
