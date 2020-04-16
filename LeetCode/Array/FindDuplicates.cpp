#include <bits/stdc++.h>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++) {
            if(freq[nums[i]] == 1)
                return true;
            freq[nums[i]]++;
        }
        return false;
    }
};