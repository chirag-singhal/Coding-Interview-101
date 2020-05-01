#include <bits/stdc++.h>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int n = nums.size();
        int last = n - 1;
        for(int i = n - 2; i > -1; i--)
            if(nums[i] + i >= last)
                last = i;
        return last == 0;
    }
};