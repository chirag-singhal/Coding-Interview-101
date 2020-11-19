## [Valid Palindrme](https://leetcode.com/problems/valid-palindrome/)

### Problem Link - https://leetcode.com/problems/valid-palindrome/

---

### Solution

```cpp

    class Solution {
    public:
        bool isPalindrome(string s) {
            int start = 0, end = s.length() - 1;
            while(start < end) {
                if((s[start] > 'z' || s[start] < 'a') && (s[start] > 'Z' || s[start] < 'A') 
                && (s[start] < '0' || s[start] > '9'))
                    start++;
                else if((s[end] > 'z' || s[end] < 'a') && (s[end] > 'Z' || s[end] < 'A') 
                && (s[end] < '0' || s[end] > '9'))
                    end--;
                else if(tolower(s[start]) != tolower(s[end])) {
                    return false;
                }
                else {
                    start++;
                    end--;
                }
            }
            return true;
        }
    };


```