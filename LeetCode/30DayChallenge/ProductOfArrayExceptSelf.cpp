#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> ans;
        int pro = 1;
        for(int i = 0; i < nums.size(); i++) {
            ans.push_back(pro);
            pro *= nums[i];
        }
        pro = 1;
        for(int i = nums.size() - 1; i > -1; i--) {
            ans[i] *= pro;
            pro *= nums[i];
        }
        return ans;
    }
};