#include <bits/stdc++.h>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int start = 0; 
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != 0) 
                nums[start++] = nums[i];
        while(start < nums.size())
            nums[start++] = 0;
    }
};