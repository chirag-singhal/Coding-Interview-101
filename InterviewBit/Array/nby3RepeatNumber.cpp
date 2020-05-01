#include <bits/stdc++.h>

int repeatedNumber(const std::vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n1 = INT_MAX, n2 = INT_MAX;
    int count1 = 0, count2 = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == n1) {
            count1++;
            continue;
        }
        if(A[i] == n2) {
            count2++;
            continue;
        }
        if(count1 == 0) {
            n1 = A[i];
            count1++;
            continue;
        }
        if(count2 == 0) {
            n2 = A[i];
            count2++;
            continue;
        }
        else {
            count1--;
            count2--;
        }
    }
    count1 = 0, count2 = 0;
    int n = A.size();
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == n1)
            count1++;
        if(A[i] == n2)
            count2++;
        if(count1 > n / 3)
            return n1;
        
        if(count2 > n / 3)
            return n2;
    }
    return -1;
}
