#include <bits/stdc++.h>

void rotate(std::vector<std::vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    for(int i = 0; i < A.size() / 2; i++) {
        for(int j = i; j < A.size() - i - 1; j++) {
            int temp = A[i][j]; 
            A[i][j] = A[A.size() - 1 - j][i];
            
            A[A.size() - j - 1][i] = A[A.size() - 1 - i][A.size() - j - 1];
            
            A[A.size() - 1 - i][A.size() - j - 1] = A[j][A.size() - i - 1];
            
            A[j][A.size() - i - 1] = temp;
        }
    }
}
