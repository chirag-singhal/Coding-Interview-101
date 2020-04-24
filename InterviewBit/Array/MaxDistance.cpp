#include <bits/stdc++.h>

int max(int a, int b) {
    if(a > b)
        return a;
    return b;
}

int min(int a, int b) {
    if(a < b)
        return a;
    return b;
}

int maximumGap(const std::vector<int> &A) {
    int n = A.size();
    if(n == 0)
        return -1;
    int maxCount = -1;
    std::vector<int> LMin(n, 0);
    std::vector<int> RMax(n, 0);
    LMin[0] = A[0];
    RMax[n - 1] = A[n - 1];
    for(int i = 1; i < n; i++)
        LMin[i] = min(LMin[i - 1], A[i]);
    for(int i = n - 2; i > -1; i--) {
        RMax[i] = max(RMax[i + 1], A[i]);
        //cout<<RMax[i]<<" "<<RMax[i + 1]<<endl;
    }
    int i = 0, j = 0;
    while(i < n && j < n) {
        //cout<<LMin[i]<<RMax[j]<<endl;
        if(LMin[i] <= RMax[j]) {
            maxCount = max(maxCount, j - i);
            j++;
        }
        else i++;
    }
    return maxCount;
}
