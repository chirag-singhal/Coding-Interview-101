#include <bits/stdc++.h>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int num = 0;
        for(auto i = nums.begin(); i != nums.end(); ++i)
            num = num ^ *i;
        
        return num;
    }
};