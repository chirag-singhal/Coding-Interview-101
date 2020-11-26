## Third Maximum Number](https://leetcode.com/problems/third-maximum-number/)

### Problem Link - https://leetcode.com/problems/third-maximum-number/

---

### Solution

```cpp

    class Solution {
    public:
        int thirdMax(vector<int>& nums) {
            long int a = (long)INT_MIN - 1, b = (long)INT_MIN - 1, c = (long)INT_MIN - 1;
            for(int i = 0; i < nums.size(); i++) {
                if(a < nums[i]) {
                    c = b;
                    b = a;
                    a = nums[i];
                }
                else if(a == nums[i]) {
                    continue;
                }
                else if(b < nums[i]) {
                    c = b;
                    b = nums[i];
                }
                else if(b == nums[i]) {
                    continue;
                }
                else if (c < nums[i]) {
                    c = nums[i];
                }
            }
            if(c == (long)INT_MIN - 1)
                return a;
            return c;
        }
    };

```