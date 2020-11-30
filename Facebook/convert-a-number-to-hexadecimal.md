## [Convert a Number to Hexadecimal](https://leetcode.com/problems/convert-a-number-to-hexadecimal/)

### Problem Link - https://leetcode.com/problems/convert-a-number-to-hexadecimal/

---

### Solution

```cpp

    class Solution {
    public:
        string toHex(int num) {
            if(num == 0)
                return "0";
            string ans = "";
            vector<int> powTwo{1, 2, 4, 8};
            for(int i = 0; i < 8; i++) {
                int temp = 0;
                for(int j = 0; j < 4; j++) {
                    temp += powTwo[j] * (num & 1);
                    num = num >> 1;
                }
                if(temp != 0 || num != 0) {
                    if(temp < 10)
                        ans = (char)(temp + '0') + ans;
                    else 
                        ans = (char)(temp - 10 + 'a') + ans;
                }
            }
            return ans;
        }
    };
    
```