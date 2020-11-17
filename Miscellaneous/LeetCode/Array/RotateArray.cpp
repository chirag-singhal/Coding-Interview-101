#include <bits/stdc++.h>

class Solution {
public:
    
    void reverse(std::vector<int>& nums, int start, int end) {
        for(int i = start; i <= (end + start) / 2; i++) {
            int temp = nums[i];
            nums[i] = nums[start + end - i];
            nums[end + start - i] = temp;
        }
    }
    
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - 1 - k);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};