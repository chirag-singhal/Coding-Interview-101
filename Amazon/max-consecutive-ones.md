## [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/)

### Problem Link - https://leetcode.com/problems/max-consecutive-ones/

---

### Solution

```cpp

    class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int count = 0;
            int maxOnes = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == 1)
                    count++;
                else {
                    maxOnes = max(maxOnes, count);
                    count = 0;
                }
            }
            maxOnes = max(maxOnes, count);
            return maxOnes;
        }
    };

```