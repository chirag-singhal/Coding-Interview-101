#include <bits/stdc++.h>

int maxArr(std::vector<int> &A) {
    int max1 = A[0] + 1, max2 = A[0] - 1;
    int min1 = A[0] + 1, min2 = A[0] - 1;
    for(int i = 0; i < A.size(); i++) {
        int a = A[i] + i + 1;
        int b = A[i] - i - 1;
        if(max1 < a)
            max1 = a;
        if(min1 > a)
            min1 = a;
        if(max2 < b)
            max2 = b;
        if(min2 > b)
            min2 = b;
    }
    if(max1 - min1 > max2 - min2)
        return max1 - min1;
    return max2 - min2;
}
