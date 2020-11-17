#include <bits/stdc++.h>

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class BinaryMatrix {
public:
    int get(int x, int y);
    std::vector<int> dimensions();
};

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        std::vector<int> size = binaryMatrix.dimensions();
        int n = size[0];
        int m = size[1];
        int leftColumn = -1;
        int r = 0;
        int c = m - 1;
        while(r < n && c > -1) {
            int x = binaryMatrix.get(r, c);
            if(x == 0)
                r++;
            else {
                leftColumn = c;
                c--;
            }
        }
        return leftColumn;
    }
};