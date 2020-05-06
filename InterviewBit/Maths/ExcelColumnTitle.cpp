#include <bits/stdc++.h>

std::string convertToTitle(int A) {
    std::string s;
    while(A > 0) {
        int r2 = A % 26;
        char c;
        if(r2 == 0) {
            c = 'Z';
            A = A / 26 - 1;
        }
        else { 
            c = 'A' + r2 - 1;
            A = A / 26;
        }
        std::string s1(1, c);
        s = s1 + s;
    }
    return s;
}
