#include <bits/stdc++.h>

bool hotel(std::vector<int> &arrive, std::vector<int> &depart, int K) {
    std::vector<std::pair<int, int>> arr;
    for(int i = 0; i < arrive.size(); i++) {
        arr.push_back(std::make_pair(arrive[i], 0));
        arr.push_back(std::make_pair(depart[i], 1));
    }
    std::sort(arr.begin(), arr.end());
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        while(i < arr.size() - 1 && arr[i].first == arr[i + 1].first) {
            if(arr[i++].second == 0) 
                count++;
            else count--;
        }
        if(arr[i].second == 0) 
            count++;
        else count--;
        if(count > K)
            return false;
    }
    return true;
}
