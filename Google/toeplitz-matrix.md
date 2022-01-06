## [Toeplitz Matrix](https://leetcode.com/problems/toeplitz-matrix/)

### Problem Link - https://leetcode.com/problems/toeplitz-matrix/

---

### Solution

```cpp

    class Solution {
    public:
        bool isToeplitzMatrix(vector<vector<int>>& matrix) {
            for(int i = 0; i < matrix.size() - 1; i++) {
                int ele = matrix[i][0];
                for(int j = i + 1, k = 1; j < matrix.size() && k < matrix[0].size(); j++, k++) {
                    if(ele != matrix[j][k])
                        return false;
                }
            }
            for(int i = 1; i < matrix[0].size() - 1; i++) {
                int ele = matrix[0][i];
                for(int j = i + 1, k = 1; j < matrix[0].size() && k < matrix.size(); j++, k++) {
                    if(ele != matrix[k][j])
                        return false;
                }
            }
            return true;
        }
};


```