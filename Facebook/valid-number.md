## [Valid Number](https://leetcode.com/problems/valid-number/)

### Problem Link - https://leetcode.com/problems/valid-number/

---

### Solution

```cpp
    class Solution {
    public:
        bool isInteger(string s) {
            if(s.length() == 0) 
                return false;
            if(s.length() == 1) 
                return s[0] >= '0' && s[0] <= '9';
            for(int i = 0; i < s.length(); i++) {
                if(s[i] < '0' || s[i] > '9') {
                    if(i == 0 && (s[i] == '+' || s[i] == '-'))
                        continue;
                    return false;
                }
            }
            return true;
        }
        
        bool isDecimal(string s) {
            if(s.length() == 0) 
                return false;
            int bdec = 0;
            int adec = 0;
            int dec = 0;
            for(int i = 0; i < s.length(); i++) {
                if(s[i] < '0' || s[i] > '9') {
                    if(i == 0 && (s[i] == '+' || s[i] == '-'))
                        continue;
                    if(s[i] == '.') {
                        dec++;
                        continue;
                    }
                    return false;
                }
                if(dec == 0)
                    bdec++;
                else
                    adec++;
            }
            if(dec != 1)
                return false;
            if(adec == 0 && bdec == 0)
                return false;
            return true;
        }
        
        bool isNumber(string s) {
            if(s.length() == 0) 
                return false;
            int eidx = -1;
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == 'e' || s[i] == 'E') {
                    eidx = i;
                    break;
                }
            }
            if(eidx == -1) 
                return isDecimal(s) || isInteger(s);
            
            string s1 = s.substr(0, eidx);
            string s2 = s.substr(eidx + 1, s.length() - eidx - 1);
            
            return (isDecimal(s1) || isInteger(s1)) && isInteger(s2);
        }
    };


```