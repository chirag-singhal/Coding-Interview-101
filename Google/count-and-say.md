## [Count And Say](https://leetcode.com/problems/count-and-say/)

### Problem Link - https://leetcode.com/problems/count-and-say/

---

### Solution

```cpp

    class Solution {
    public:
        string countAndSay(int n) {
            if(n == 1)
                return "1";
            string ans = "1";
            for(int i = 2; i <= n; i++) {
                string temp = "";
                int count  = 1;
                for(int j = 0; j < ans.length() - 1; j++) {
                    if(ans[j] == ans[j + 1]) {
                        count++;
                    }
                    else {
                        temp += to_string(count) + ans[j];
                        count = 1;
                    }
                }
                temp += to_string(count) + ans[ans.length() - 1];
                ans = temp;
            }
            return ans;
        }
    };

```