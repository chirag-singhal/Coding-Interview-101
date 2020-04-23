#include <bits/stdc++.h>

std::vector<int> wave(std::vector<int> &A) {
    std::sort(A.begin(), A.end());
    for(int i = 0; i < A.size() - 1; i += 2) {
        int temp = A[i];
        A[i] = A[i + 1];
        A[i + 1] = temp;
    }
    return A;
}
