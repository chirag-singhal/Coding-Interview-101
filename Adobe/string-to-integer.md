## [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)

### Problem Link - https://leetcode.com/problems/string-to-integer-atoi/

---

### Solution

```cpp

    class Solution {
    public:
        int myAtoi(string s) {
            long int ans = 0;
            bool pos = true;
            int i = 0;
            while(s[i] == ' ')
                i++;
            if(s[i] == '-')
                pos = false;
            if(!pos || s[i] == '+')
                i++;
            while(s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10 + (s[i] - '0');
                i++;
                if(ans > INT_MAX && !pos)
                    return INT_MIN;
                else if(ans > INT_MAX && pos)
                    return INT_MAX;
            }
            return pos ? (int)ans : -(int)ans;
        }
    };

```