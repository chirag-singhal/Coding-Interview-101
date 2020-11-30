## [Rotate String](https://leetcode.com/problems/rotate-string/)

### Problem Link - https://leetcode.com/problems/rotate-string/

---

### Solution

```cpp

    class Solution {
    public:
        bool rotateString(string A, string B) {
            if(A.length() != B.length())
                return false;
            if(A.length() == 0)
                return true;
            for(int i = 0; i < A.length(); i++) {
                if(A[i] == B[0]) {
                    int j = (i + 1) % A.length(), k = 1;
                    while(j != i) {
                        if(A[j] != B[k])
                            break;
                        j = (j + 1) % A.length();
                        k++;
                    }
                    if(j == i)
                        return true;
                }
            }
            return false;
        }
    };

```