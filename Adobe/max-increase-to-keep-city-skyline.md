## [Max Increase to Keep City Skyline](https://leetcode.com/problems/max-increase-to-keep-city-skyline/)

### Problem Link - https://leetcode.com/problems/max-increase-to-keep-city-skyline/

---

### Solution

```cpp

    class Solution {
    public:
        int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
            vector<int> top(grid[0].size(), 0);
            vector<int> left(grid.size(), 0);
            int ans = 0;
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[i].size(); j++) {
                    left[i] = max(grid[i][j], left[i]); 
                }
            }
            for(int i = 0; i < grid[0].size(); i++) {
                for(int j = 0; j < grid.size(); j++) {
                    top[i] = max(grid[j][i], top[i]); 
                }
            }
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[i].size(); j++) {
                    ans += min(top[j], left[i]) - grid[i][j];
                }
            }
            return ans;
        }
    };

```