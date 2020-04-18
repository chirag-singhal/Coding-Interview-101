#include<bits/stdc++.h>

class Solution {
public:
    int min(int a, int b) {
        if(a < b)
            return a;
        return b;
    }
    int minPathSum(std::vector<vector<int>>& grid) {
        int cost[grid.size()][grid[0].size()];
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                cost[i][j] = 0;
            }
        }
        cost[0][0] = grid[0][0];
        for(int i = 1; i < grid.size(); i++) 
            cost[i][0] = cost[i - 1][0] + grid[i][0];
        for(int i = 1; i < grid[0].size(); i++) 
            cost[0][i] = cost[0][i - 1] + grid[0][i];
        
        for(int i = 1; i < grid.size(); i++) {
            for(int j = 1; j < grid[0].size(); j++) {
                cost[i][j] = grid[i][j] + min(cost[i - 1][j], cost[i][j - 1]);
            }
        }
        return cost[grid.size() - 1][grid[0].size() - 1];
    }
};