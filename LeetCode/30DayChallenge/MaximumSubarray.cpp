#include <bits/stdc++.h>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max_sum, cur_sum;
        max_sum = cur_sum = 0;
        
        for(auto i = nums.begin(); i != nums.end(); i++) {
            cur_sum += *i;
            
            if(cur_sum < 0)
                cur_sum = 0;
            
            else if(cur_sum > max_sum)
                max_sum = cur_sum;
        }
        if(max_sum == 0) {
            max_sum = nums.front();
            for(auto i = nums.begin(); i != nums.end(); i++) {
                if(max_sum < *i)
                    max_sum = *i;
            }
        }
        return max_sum;
    }
};