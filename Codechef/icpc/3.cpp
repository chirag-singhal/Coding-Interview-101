#include <iostream>
#include <bits/stdc++.h>

bool compareTwoLine(lineSegment a, lineSegment b) 
{ 
    return a.V < b.V; 
} 


struct lineSegment {
    long int L;
    long int R;
    long int V;
};

int main() {

    int t;
    std::cin>>t;
    for(int i  = 0; i < t; i++) {
        int n;
        std::cin>>n;
        struct lineSegment prob[n];
        for(int j = 0; j < n; j++) {
            std::cin>>prob[i].L;
            std::cin>>prob[i].R;
            std::cin>>prob[i].V;
        }
        std::sort(prob, prob + n, compareTwoLine);
    }

    return 0;
}