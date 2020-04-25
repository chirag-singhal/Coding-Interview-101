#include <bits/stdc++.h>

int repeatedNumber(const std::vector<int> &A) {
    int sq = sqrt(A.size());
    std::vector<int> arr(A.size() / sq + 1, 0);
    for(int i = 0; i < A.size(); i++) {
        arr[(A[i] - 1) / sq]++;
    }
    int selected = A.size() / sq;
    for(int i = 0; i < arr.size() - 1; i++) {
        if(arr[i] > sq)
            selected = i;
    }
    std::unordered_map<int, int> count;
    int maxRange = (selected + 1) * sq;
    int minRange = selected * sq;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] <= maxRange  && A[i] > minRange) {
            count[A[i]]++;
            if(count[A[i]] > 1)
                return A[i];
        }
    }
    return -1;
}
