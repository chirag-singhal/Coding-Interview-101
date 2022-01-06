## [Word Pattern](https://leetcode.com/problems/word-pattern/)

### Problem Link - https://leetcode.com/problems/word-pattern/

---

### Solution

```cpp

    class Solution {
    public:
        bool wordPattern(string pattern, string s) {
            unordered_map<char, string> map;
            unordered_map<string, int> count;
            int i = 0;
            for(int j = 0; j < pattern.length(); j++) {
                string word = "";
                for(; i < s.length() && s[i] != ' '; i++) {
                    word += s[i];
                }
                i++;
                if(word == "")
                    return false;
                if(map[pattern[j]] == "") {
                    map[pattern[j]] = word;
                    count[word]++;
                    if(count[word] > 1)
                        return false;
                }
                else if(map[pattern[j]] != word)
                    return false;
            }
            if(i < s.length())
                return false;
            return true;
        }
    };


```