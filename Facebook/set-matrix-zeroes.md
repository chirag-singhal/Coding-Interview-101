## [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/description/)

### Problem Link - https://leetcode.com/problems/set-matrix-zeroes/description/

---

### Solution

```cpp

    class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            unordered_map<int, int> row;
            unordered_map<int, int> col;
    
            for(int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    if(matrix[i][j] == 0) {
                        row[i] = 1;
                        col[j] = 1;
                    }
                }
            }
    
            for(int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    if(row[i] == 1 || col[j] == 1) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    };
    

```