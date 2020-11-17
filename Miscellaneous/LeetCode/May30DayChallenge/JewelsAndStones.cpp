#include <bits/stdc++.h>

class Solution {
public:
    int numJewelsInStones(std::string J, std::string S) {
        std::unordered_map<char, int> jewel;
        for(int i = 0; i < J.length(); i++)
            jewel[J[i]] = 1;
        int count = 0;
        for(int i = 0; i < S.length(); i++)
            if(jewel[S[i]] == 1)
                count++;
        return count;
    }
};