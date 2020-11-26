## [Decode Ways](https://leetcode.com/problems/decode-ways/)

### Problem Link - https://leetcode.com/problems/decode-ways/

---

### Solution

```cpp

    class Solution {
    public:
        int numDecodings(string s) {
            if(s.length() == 0)
                return 0;
            if(s[0] == '0')
                return 0;
            vector<int> arr(s.length() + 1, 0);
            arr[0] = 1;
            arr[1] = 1;
            for(int i = 1; i < s.length(); i++) {
                if(s[i] == '0' && (s[i - 1] == '1' || s[i - 1] == '2')) {
                    arr[i + 1] += arr[i - 1];
                }
                else if(s[i] == '0') {
                    return 0;
                }
                else if(s[i + 1] != '0' && (s[i - 1] == '1' || 
                        (s[i - 1] == '2' && s[i] < '7'))) {
                    arr[i + 1] = arr[i] + arr[i - 1];
                }
                else {
                    arr[i + 1] += arr[i];
                }
            }
            return arr[s.length()];
        }
    };


```