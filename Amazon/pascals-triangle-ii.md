## [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/)

### Problem Link - https://leetcode.com/problems/pascals-triangle-ii/

---

### Solution

```cpp

    class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int> ans(rowIndex + 1);
            for(int i = 0; i <= rowIndex; i++) {
                if(i == 0 || i == rowIndex)
                    ans[i] = 1;
                else
                    ans[i] = (int)(((long)ans[i - 1] * (long)(rowIndex + 1 - i)) / i);
            }
            return ans;
        }
    };

```