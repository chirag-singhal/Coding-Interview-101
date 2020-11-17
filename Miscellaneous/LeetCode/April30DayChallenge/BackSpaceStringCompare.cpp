#include <bits/stdc++.h>

class Solution {
public:
    bool backspaceCompare(std::string S, std::string T) {
        std::stack<char> S1;
        std::stack<char> T1;
        int n1 = S.length();
        int n2 = T.length();
        for(int i = 0; i < n1; i++) {
            if(S[i] == '#'){
                if(!S1.empty())
                    S1.pop();
            }
            else 
                S1.push(S[i]);
        }
        for(int i = 0; i < n2; i++) {
            if(T[i] == '#'){
                if(!T1.empty())
                    T1.pop();
            }
            else 
                T1.push(T[i]);
        }
        bool same = true;
        while(!S1.empty() && !T1.empty()) {
            if(S1.top() != T1.top()) {
                same = false;
                break;
            }
            else {
                S1.pop();
                T1.pop();
            }
        }
        if(!S1.empty() || !T1.empty())
            same = false;
        return same;
    }
};