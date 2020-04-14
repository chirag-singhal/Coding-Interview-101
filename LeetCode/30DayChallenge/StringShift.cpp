#include <bits/stdc++.h>

class Solution {
public:
    std::string stringShift(std::string s, std::vector<std::vector<int>>& shift) {
        int rshift = 0, lshift = 0;
        for(int i = 0; i < shift.size(); i++) {
            if(shift[i][0] == 0)
                lshift += shift[i][1];
            else 
                rshift += shift[i][1];
        }
        if(lshift == rshift)
            return s;
        else if(rshift > lshift) {
            int shift = rshift - lshift;
            rightShift(s, shift);    
        }
        else {
            int shift = lshift - rshift;
            leftShift(s, shift);
        }
        return s;
    }
    
    void leftShift(std::string &s, int x) {
        x = x % s.length();
        std::reverse(s.begin(), s.begin() + x);
        std::reverse(s.begin() + x, s.end());
        std::reverse(s.begin(), s.end());
    }
    
    void rightShift(std::string &s, int x) {
        x = x % s.length();
        leftShift(s, s.length() - x);
    }
};