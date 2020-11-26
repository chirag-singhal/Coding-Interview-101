## [Buddy Strings](https://leetcode.com/problems/buddy-strings/)

### Problem Link - https://leetcode.com/problems/buddy-strings/

---

### Solution

```cpp

    class Solution {
    public:
        bool buddyStrings(string A, string B) {
            if(A.length() != B.length())
                return false;
            int first = -1;
            int second = -1;
            unordered_map<char, int> map;
            bool same = false;
            for(int i = 0; i < A.length(); i++) {
                if(A[i] != B[i]) {
                    if(first == -1)
                        first = i;
                    else if(second == -1)
                        second = i;
                    else
                        return false;
                }
                if(map[A[i]] != 0)
                    same = true;
                map[A[i]] = 1;
            }
            if(first == -1 ^ second == -1)
                return false;
            if(first == -1 && second == -1 && same)
                return true;
            if(first == -1 && second == -1)
                return false;
            if(A[first] == B[second] && A[second] == B[first])
                return true;
            return false;
        }
    };

```