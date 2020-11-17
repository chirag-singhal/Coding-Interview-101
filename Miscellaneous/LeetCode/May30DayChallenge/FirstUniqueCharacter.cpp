#include <bits/stdc++.h>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::list<char> l;
        std::unordered_map<char, std::list<char>::const_iterator> map;
        std::unordered_map<char, int> a;
        for(int i = 0; i < s.length(); i++) {
            auto it = map.find(s[i]);
            if(it != map.end()) {
                if(a[s[i]] != 2) {
                    l.erase(map[s[i]]);   
                    a[s[i]] = 2;
                }
            }
            else {
                l.push_front(s[i]);
                map[s[i]] = l.cbegin();
            }
        }
        if(l.size() != 0) {
            char c = l.back();
            for(int i = 0; i < s.length(); i++)
                if(c == s[i])
                    return i;
        }
        return -1;
    }
};