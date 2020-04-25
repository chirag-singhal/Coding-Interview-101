#include <bits/stdc++.h>

//Time Complexity O(nlogn)
std::vector<int> SubUnsort(std::vector<int> &A) {
    std::vector<int> B = A;
    std::sort(B.begin(), B.end());
    int l = -1, r = -1;
    for(int i = 0; i < B.size(); i++) {
        if(A[i] != B[i]) {
            if(l == -1)
                l = i;
            else
                r = i;
        }
    }
    std::vector<int> ans;
    if(l == -1)
        ans.push_back(-1);
    else {
        ans.push_back(l);
        ans.push_back(r);
    }
    return ans;
}

//Time Complexity O(n)
std::vector<int> subUnsort(std::vector<int> &A) {
    std::vector<int> ans;
    int l = -1, r = -1;
    int min = INT_MAX, max = INT_MIN;
    int lmaxIndex = -1, rminIndex = -1;
    for(int i = 0; i < A.size() - 1; i++) {
        if(A[i + 1] < A[i]) {
            l = i;
            break;
        }
    }
    for(int i = A.size() - 1; i > 0; i--) {
        if(A[i - 1] > A[i]) {
            r = i;
            break;
        }
    }
    for(int i = l; i < r + 1; i++) {
        if(min > A[i])
            min = A[i];
        if(max < A[i])
            max = A[i];
    }
    
    for(int i = 0; i < l; i++) {
        if(A[i] > min) {
            l = i;
            break;
        }
    }
    
    for(int i = A.size() - 1; i > r; i--) {
        if(A[i] < max) {
            r = i;
            break;
        }
    }
    if(l == -1)
        ans.push_back(-1);
    else {
        ans.push_back(l);
        ans.push_back(r);
    }
    return ans;
}

