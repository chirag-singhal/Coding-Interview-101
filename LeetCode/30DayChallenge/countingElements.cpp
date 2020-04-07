#include <bits/stdc++.h>

class Solution {
public:
    int countElements(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int n = arr.size();
        int prevNum = arr[0];
        int prevCount = 0, count = 0;
        for(int i = 0; i < n; i++) {
            if(prevNum == arr[i]) {
                prevCount++;
            }
            else if(arr[i] == prevNum + 1) {
                prevNum = arr[i];
                count += prevCount;
                prevCount = 1;
            }
            else {
                prevNum = arr[i];
                prevCount = 1;
            }
        }
        return count;
    }
};