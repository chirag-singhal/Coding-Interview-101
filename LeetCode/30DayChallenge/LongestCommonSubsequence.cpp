#include <bits/stdc++.h>

class Solution {
public:
    int max(int a, int b) {
        if(a > b)
            return a;
        return b;
    }
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        int dp[n1 + 1][n2 + 1];
        
        for(int i = 0; i <= n1; i++) {
            for(int j = 0; j <= n2; j++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[n1][n2];
    }
};