#include <bits/stdc++.h>

class Solution {
public:
    void fill(std::vector<std::vector<int>>& image, std::vector<std::vector<int>>& visited, int sr, int sc, int newColor, int oldColor) {
        if(sr >= image.size() || sc >= image[0].size() || sr < 0 || sc < 0)
            return;
        if(image[sr][sc] != oldColor)
            return;
        if(visited[sr][sc] == 1)
            return;
        image[sr][sc] = newColor;
        visited[sr][sc] = 1;
        fill(image, visited, sr - 1, sc, newColor, oldColor);
        fill(image, visited, sr + 1, sc, newColor, oldColor);
        fill(image, visited, sr, sc + 1, newColor, oldColor);
        fill(image, visited, sr, sc - 1, newColor, oldColor);
    }
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
        std::vector<std::vector<int>> visited;
        for(int i = 0; i < image.size(); i++) {
            std::vector<int> v1(image[i].size(), 0);
            visited.push_back(v1);
        }
        fill(image, visited, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};