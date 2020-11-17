#include <bits/stdc++.h>

std::vector<int> maxset(std::vector<int> &A) {
    std::vector<int> ans;
    bool found = false;
    long int sum = 0, maxSum = 0;
    int currStart = 0, maxStart = 0, end = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] >= 0)
            found = true;
        if(A[i] < 0) {
            sum = 0;
            currStart = i + 1;
            continue;
        }
        sum += A[i];
        if(sum == maxSum && end - maxStart < i - currStart) {
            maxStart = currStart;
            end = i;
        }
        if(sum > maxSum) {
            maxStart = currStart;
            maxSum = sum;
            end = i;
        }
    }
    if(!found)
        return ans;
    for(int i = maxStart; i <= end; i++)
        ans.push_back(A[i]);
    return ans;
}
