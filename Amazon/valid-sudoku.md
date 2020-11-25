## [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)

### Problem Link - https://leetcode.com/problems/valid-sudoku/

---

### Solution

```cpp

    class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            for(int i = 0; i < 9; i++) {
                vector<int> arr(9, 0);
                for(int j = 0; j < 9; j++) {
                    if(board[i][j] != '.' && arr[board[i][j] - '1'] != 0)
                        return false;
                    if(board[i][j] == '.')
                        continue;
                    arr[board[i][j] - '1'] = 1;
                }
            }
            for(int i = 0; i < 9; i++) {
                vector<int> arr(9, 0);
                for(int j = 0; j < 9; j++) {
                    if(board[j][i] != '.' && arr[board[j][i] - '1'] != 0)
                        return false;
                    if(board[j][i] == '.')
                        continue;
                    arr[board[j][i] - '1'] = 1;
                }
            }
            for(int i = 0; i < 9; i++) {
                vector<int> arr(9, 0);
                for(int j = 0; j < 3; j++) {
                    for(int k = 0; k < 3; k++) {
                        if(board[j + (i / 3) * 3][k + (i % 3) * 3] != '.' && arr[board[j + (i / 3) * 3][k + (i % 3) * 3] - '1'] != 0)
                            return false;
                        if(board[j + (i / 3) * 3][k + (i % 3) * 3] == '.')
                            continue;
                        arr[board[j + (i / 3) * 3][k + (i % 3) * 3] - '1'] = 1;
                    }    
                }
            }
            return true;
        }
    };

```