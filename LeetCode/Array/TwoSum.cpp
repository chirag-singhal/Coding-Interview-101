#include<bits/stdc++.h>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        std::vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(map[target - nums[i]] != 0) {
                ans.push_back(map[target - nums[i]] - 1);
                ans.push_back(i);
                break;
            }
            map[nums[i]] = i + 1;
        }
        return ans;
    }
};