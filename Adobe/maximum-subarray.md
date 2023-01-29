## [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/description/)

### Problem Link - https://leetcode.com/problems/maximum-subarray/description/

---

### Solution

```cpp

    class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int maxSum = INT_MIN;
            int currSum = 0;
            for(int i = 0; i < nums.size(); i++) {
                currSum += nums[i];
                if(currSum > maxSum)
                    maxSum = currSum;
                if(currSum < 0)
                    currSum = 0;
            }
            return maxSum;
        }
    };
    

```