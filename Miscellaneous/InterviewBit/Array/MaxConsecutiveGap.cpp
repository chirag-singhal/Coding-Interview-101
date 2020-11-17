#include <bits/stdc++.h>

int maximumGap(const std::vector<int> &A) {
    if(A.size() < 2)
        return 0;
    int max = A[0], min = A[0];
    for(int i = 1; i < A.size(); i++) {
        if(max < A[i])
            max = A[i];
        if(min > A[i])
            min = A[i];
    }
    std::vector<int> maxB(A.size(), INT_MIN);
    std::vector<int> minB(A.size(), INT_MAX);
    
    double range = (double)(max - min) / (double)(A.size() - 1);
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == min || A[i] == max)
            continue;
        int index = (int)floor((double)(A[i] - min) / range);
        if(maxB[index] == INT_MIN)
            maxB[index] = A[i];
        else if(maxB[index] < A[i])
            maxB[index] = A[i];
        if(minB[index] == INT_MAX)
            minB[index] = A[i];
        else if(minB[index] > A[i])
            minB[index] = A[i];
    }
    int prev = min;
    int maxgap = 0;
    for(int i = 0; i < A.size() - 1; i++) {
        if(minB[i] == INT_MAX)
            continue;
        if(maxgap < minB[i] - prev)
            maxgap = minB[i] - prev;
        prev = maxB[i];
    }
    if(maxgap < max - prev)
        maxgap = max - prev;
    return maxgap;
}
