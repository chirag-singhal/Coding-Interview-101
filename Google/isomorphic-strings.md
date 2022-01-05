## [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)

### Problem Link - https://leetcode.com/problems/isomorphic-strings/

---

### Solution

```cpp

    class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            unordered_map<char, int> map;
            unordered_map<char, bool> visited;
            for(int i = 0; i < s.length(); i++) {
                if(map[s[i]] == 0) {
                    if(visited[t[i]] == true)
                        return false;
                    visited[t[i]] = true;
                    map[s[i]] = t[i];
                }
                else {
                    if(map[s[i]] != t[i])
                        return false;
                }
            }
            return true;
        }
    };

```