## [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/)

### Problem Link - https://leetcode.com/problems/reverse-words-in-a-string/

---

### Solution

```cpp

    class Solution {
    public:
        string reverseWords(string s) {
            int i = s.length() - 1;
            string ans = "";
            while(i >= 0 && s[i] == ' ')
                i--;
            for(; i >= 0; ){
                string temp = "";
                while(i >= 0 && s[i] != ' ') {
                    temp = s[i] + temp;
                    i--;
                }
                while(i >= 0 && s[i] == ' ')
                    i--;
                ans += temp;
                if(i >= 0)
                    ans += ' ';
            }
            return ans;
        }
    };

```