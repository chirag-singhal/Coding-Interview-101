## [Find Pivot Index](https://leetcode.com/problems/find-pivot-index/)

### Problem Link - https://leetcode.com/problems/find-pivot-index/

---

### Solution

```cpp

    class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            int sum = 0, currSum = 0;
            for(int i = 0; i < nums.size(); i++)
                sum += nums[i];
            for(int i = 0; i < nums.size(); i++) {
                if(currSum == sum - currSum - nums[i])
                    return i;
                currSum += nums[i];
            }
            return -1;
        }
    };

```