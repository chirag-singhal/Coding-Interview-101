#include <bits/stdc++.h>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
        while(stones.size() > 1) {
            int first = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            int sec = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            
            if(first == sec)
                continue;
            else {
                int dif = sec > first ? sec - first : first - sec;
                stones.push_back(dif);
                push_heap(stones.begin(), stones.end());
            }
        }
        if(stones.size() == 0)
            return 0;
        else return stones.front();
    }
};