#include <bits/stdc++.h>

void reverse(std::vector<int> &A, int start) {
    for(int i = start; i < (A.size() + start) / 2; i++) {
        int temp = A[i];
        A[i] = A[A.size() - i + start - 1];
        A[A.size() - i + start - 1] = temp;
    }
}

std::vector<int> nextPermutation(std::vector<int> &A) {
    int sel = -1;
    for(int i = A.size() - 1; i > 0; i--) {
        if(A[i - 1] < A[i]) {
            sel = i - 1;
            break;
        }
    }
    if(sel == -1) {
        reverse(A, 0);
        return A;
    }
    int index = -1;
    int lo = sel + 1, hi = A.size() - 1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(A[mid] <= A[sel])
            hi = mid - 1;
        else {
            lo = mid + 1;
            if(index == -1 || A[index] >= A[mid])
                index = mid;
        }
    }
    int temp = A[index];
    A[index] = A[sel];
    A[sel] = temp;
    
    reverse(A, sel + 1);
    return A;
}
