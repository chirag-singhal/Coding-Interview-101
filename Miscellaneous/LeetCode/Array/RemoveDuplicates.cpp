#include <bits/stdc++.h>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int k = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i - 1]) 
                nums[k++] = nums[i];
        }
        return k;
    }
};