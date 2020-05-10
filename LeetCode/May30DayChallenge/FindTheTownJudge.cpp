#include <bits/stdc++.h>

class Solution {
public:
    int findJudge(int N, std::vector<std::vector<int>>& trust) {
        std::unordered_map<int, int> map1, map2;
        for(int i = 0; i < trust.size(); i++) {
            map1[trust[i][0]]++;
            map2[trust[i][1]]++;
        }
        for(int i = 1; i <= N; i++) {
            if(map1[i] == 0 && map2[i] == N - 1)
                return i;
        }
        return -1;
    }
};