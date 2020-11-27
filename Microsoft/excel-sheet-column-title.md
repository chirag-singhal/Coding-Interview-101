## [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/)

### Problem Link - https://leetcode.com/problems/excel-sheet-column-title/

---

### Solution

```cpp

    class Solution {
    public:
        string convertToTitle(int n) {
            string ans = "";
            while(n) {
                char ch = ('A' + (n - 1) % 26);
                ans = ch + ans;
                n = (n - 1) / 26;
            }
            return ans;
        }
    };
    
```