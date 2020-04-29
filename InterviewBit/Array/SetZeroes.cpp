#include <bits/stdc++.h>

void setZeroes(std::vector<std::vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int m = A[0].size();
    std::map<int, int> map;
    for(int i = 0; i < n; i++) {
        bool found = 0;
        for(int j = 0; j < m; j++) {
            if(A[i][j] == 0) {
                map[j] = 1;
                found = 1;
            }
        }
        for(int j = 0; found && j < m; j++) 
            A[i][j] = 0;
    }
    for(int i = 0; i < m; i++) {
        if(map[i] == 1) {
            for(int j = 0; j < n; j++) {
                A[j][i] = 0;
            }
        }
    }
}
