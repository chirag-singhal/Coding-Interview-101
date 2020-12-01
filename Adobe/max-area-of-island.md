## [Max Area of Island](https://leetcode.com/problems/max-area-of-island/)

### Problem Link - https://leetcode.com/problems/max-area-of-island/

---

### Solution

```cpp

    class Solution {
    public:
        vector<int> dr{0, 1, 0, -1};
        vector<int> dc{1, 0, -1, 0};
        void visit(vector<vector<int>>& grid, vector<vector<int>>& vis, int* count, int r, int c) {
            if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
                return;
            if(grid[r][c] == 0 || vis[r][c] == 1)
                return;
            vis[r][c] = 1;
            *count = *count + 1;
            for(int i = 0; i < 4; i++)
                visit(grid, vis, count, r + dr[i], c + dc[i]);
        }
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int ans = 0;
            int count = 0;
            vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[0].size(); j++) {
                    if(grid[i][j] == 1 && vis[i][j] == 0) {
                        visit(grid, vis, &count, i, j);
                        ans = max(ans, count);
                        count  = 0;
                    }
                }
            }
            return ans;
        }
    };

```