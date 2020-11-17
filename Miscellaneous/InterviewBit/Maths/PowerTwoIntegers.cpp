#include <bits/stdc++.h>

int isPower(int A) {
    std::unordered_map<int, int> map;
    std::vector<int> keys;
    int n = A;
    for(int i = 2; i <= n && A != 1; i++) {
        if(A % i == 0)
            keys.push_back(i);
        while(A % i == 0) {
            map[i]++;
            A /= i;
        }
    }
    int min = INT_MAX;
    for(int i = 0; i < keys.size(); i++) {
        if(map[keys[i]] < min)
            min = map[keys[i]];
    }
    if(min > 1)
        return true;
    else 
        return false;
}
