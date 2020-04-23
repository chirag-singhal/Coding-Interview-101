#include <bits/stdc++.h>

int solve(std::vector<std::string> &A) {
    std::vector<float> a1;
    for(int i = 0; i < A.size(); i++)
        a1.push_back(stof(A[i]));
    float a = a1[0], b = a1[1], c = a1[2];
    for(int i = 3; i < A.size(); i++) {
        if(a + b + c > 1 && a + b + c < 2)
            return 1;
        else {
            if(a + b + c > 2) {
                if(a > b && a > c)
                    a = a1[i];
                else if(b > c) 
                    b = a1[i];
                else 
                    c = a1[i];
            }
            else {
                if(a < b && a < c)
                    a = a1[i];
                else if(b < c) 
                    b = a1[i];
                else 
                    c = a1[i];
            }
        }
    }
    if(a + b + c < 2 && a + b + c > 1)
        return 1;
    else 
        return 0;
}
