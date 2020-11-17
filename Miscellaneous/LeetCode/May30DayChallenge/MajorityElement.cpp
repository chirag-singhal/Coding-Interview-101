#include <bits/stdc++.h>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int maj = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(maj == nums[i]) 
                count++;
            else if(count == 0) {
                maj = nums[i];
                count++;
            }
            else
                count--;
        }
        count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(maj == nums[i])
                count++;
        }
        if(count > nums.size() / 2)
            return maj;
        return -1;
    }
};