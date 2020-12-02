## [Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/)

### Problem Link - https://leetcode.com/problems/valid-parenthesis-string/

---

### Solution

```cpp

    class Solution {
    public:
        bool checkValidString(string s) {
            stack<int> s1;
            stack<int> s2;
            
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == '(')
                    s1.push(i);
                else if(s[i] == '*')
                    s2.push(i);
                else {
                    if(!s1.empty())
                        s1.pop();
                    else if(!s2.empty())
                        s2.pop();
                    else 
                        return false;
                }
            }
            while(!s1.empty() && !s2.empty()) {
                if(s1.top() > s2.top()) 
                    return false;
                s1.pop();
                s2.pop();
            }
            if(!s1.empty()) 
                return false;
            return true;
            
        }
    };

```