#include <bits/stdc++.h>

std::vector<int> flip(std::string A) {
    int n = A.length();
    std::vector<int> B;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(A[i] == '1')
            B.push_back(-1);
        else {
            B.push_back(1);
            count++;
        }
    }
    std::vector<int> ans;
    if(count == 0)
        return ans;
    int sum = 0, maxSum = 0;
    int currL = 0;
    int maxL = -1, maxR = -1;
    for(int i = 0; i < n; i++) {
        sum += B[i];
        if(sum < 0){
            sum = 0;
            currL = i + 1;
        }
        if(maxSum < sum) {
            maxSum = sum;
            maxL = currL;
            maxR = i;
        }
    }
    ans.push_back(++maxL);
    ans.push_back(++maxR);
    return ans;
}
