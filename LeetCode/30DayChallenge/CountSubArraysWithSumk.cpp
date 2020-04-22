#include <bits/stdc++.h>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        std::unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(map[sum - k] != 0)
                count += map[sum - k];
            if(sum == k)
                count++;
            map[sum]++;
        }
        return count;
    }
};