#include <bits/stdc++.h>

int shift(std::vector<int>& A) {
    int j = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] > 0) {
            int temp = A[i];
            A[i] = A[j];
            A[j++] = temp;
        }
    }
    return j;
}

int firstMissingPositive(std::vector<int> &A) {
    int pos_size = shift(A);
    for(int i = 0; i < pos_size; i++) {
        if(abs(A[i]) - 1 < pos_size && A[abs(A[i]) - 1] > 0)
            A[abs(A[i]) - 1] = -A[abs(A[i]) - 1];
    }
    for(int i = 0; i < pos_size; i++)
        if(A[i] > 0)
            return i + 1;
    return pos_size + 1;
}
