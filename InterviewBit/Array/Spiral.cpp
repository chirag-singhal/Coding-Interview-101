#include <bits/stdc++.h>

std::vector<std::vector<int> > generateMatrix(int A) {
    std::vector<std::vector<int>> spiral;
    for(int i = 1; i <= A; i++) {
        std::vector<int> a;
        for(int j = 0; j < A; j++)
            a.push_back(0);
        spiral.push_back(a);
    }
    int r = 0, c = 0;
    int a = 1;
    int n = A, m = A;
    while(r < n && c < m) {
        for(int i = c; i < n; i++)
            spiral[r][i] = a++;
        r++;
        for(int i = r; i < m; i++)
            spiral[i][n - 1] = a++;
        n--;
        if(r < m) {
            for(int i = n - 1; i >= c; i--)
                spiral[m - 1][i] = a++;
            m--;
        }
        if(c < n) {
            for(int i = m - 1; i >= r; i--)
                spiral[i][c] = a++;
            c++;
        }
    }
    return spiral;
}
