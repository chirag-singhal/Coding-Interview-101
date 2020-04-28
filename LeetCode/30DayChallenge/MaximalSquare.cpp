#include <bits/stdc++.h>

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        int n1 = matrix.size();
        if(n1 == 0)
            return 0;
        int n2 = matrix[0].size();
        int max = 0;
        int square[n1][n2];
        for(int i = 0; i < n1; i++) {
            square[i][0] = matrix[i][0] - '0';
            if(square[i][0] == 1)
                max = 1;
        }
        for(int i = 0; i < n2; i++) {
            square[0][i] = matrix[0][i] - '0';
            
            if(square[0][i] == 1)
                max = 1;
        }
        
        for(int i = 1; i < n1; i++ ) {
            for(int j = 1; j < n2; j++ ) {
                if(matrix[i][j] == '1'){
                    square[i][j] = 1 + min(square[i - 1][j], min(square[i][j - 1], square[i - 1][j - 1]));
                }
                else 
                    square[i][j] = 0;
                
                if(square[i][j] > max)
                    max = square[i][j];
            }
        }
        return max * max;
    }
};