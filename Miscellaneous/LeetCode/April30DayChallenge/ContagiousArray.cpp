#include <bits/stdc++.h>

class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int max = -1;
        int sum[nums.size()];
        int n = nums.size();
        for(int i = 0; i < n; i++)
            if(nums[i] == 0) 
                nums[i] = -1;
        
        int maxsum = nums[0], minsum = nums[0];
        sum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + nums[i];
            if(maxsum < sum[i])
                maxsum = sum[i];
            if(minsum > sum[i])
                minsum = sum[i];
            if(sum[i] == 0)
                max = i + 1;
        }
        int map[maxsum - minsum + 1];
        for(int i = 0; i < maxsum - minsum + 1; i ++) {
            map[i] = -1;
        }
        for(int i = 0; i < n; i++) {
            if(map[sum[i] - minsum] == -1)
                map[sum[i] - minsum] = i;
            else if(i - map[sum[i] - minsum] > max)
                max = i - map[sum[i] - minsum];
        }
        if(max == -1)
            return 0;
        return max;
    }
};