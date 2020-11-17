#include<bits/stdc++.h>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        for(int i = digits.size() - 1; i > -1; i--) {
            digits[i]++;
            if(digits[i] > 9)
                digits[i] = 0;
            else
                break;
        }
        if(digits[0] == 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};