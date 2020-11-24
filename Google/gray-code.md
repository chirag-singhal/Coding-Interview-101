## [Gray Code](https://leetcode.com/problems/gray-code/)

### Problem Link - https://leetcode.com/problems/gray-code/

---

### Solution

```cpp

    class Solution {
    public:
        vector<int> grayCode(int n) {
            if(n == 0) {
                vector<int> ans(1, 0);
                return ans;
            }
            vector<int> ans;
            ans.push_back(0);
            for(int i = 1; i <= n; i++) {
                int num = 1 << (i - 1);
                for(int j = ans.size() - 1; j >=0; j--) {
                    ans.push_back(ans[j] + num);
                }
            }
            return ans;
        }
    };

```