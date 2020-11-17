#include <bits/stdc++.h>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::vector<int> count(26, 0);
        for(int i = 0; i < magazine.length(); i++)
            count[magazine[i] - 'a']++;
        for(int i = 0; i < ransomNote.length(); i++)
            count[ransomNote[i] - 'a']--;
        for(int i = 0; i < 26; i++)
            if(count[i] < 0)
                return false;
        return true;
    }
};