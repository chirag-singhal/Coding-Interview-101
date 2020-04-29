#include <bits/stdc++.h>

class FirstUnique {
public:
    std::unordered_map<int, std::list<int>::const_iterator> map;
    std::list<int> l;
    std::queue<int> q;
    std::unordered_map<int, int> s;
    
    FirstUnique(std::vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            auto it = map.find(nums[i]);
            if(it == map.end()) {
                s[nums[i]] = 1;
                l.push_front(nums[i]);
                map[nums[i]] = l.cbegin();
            }
            else if(s[nums[i]] != -1 && s[nums[i]] != 0) {
                l.erase(map[nums[i]]);
                s[nums[i]] = -1;
            }
            q.push(nums[i]);
        }    
    }
    
    int showFirstUnique() {
        if(l.size() == 0)
            return -1;
        return l.back();
    }
    
    void add(int value) {
        auto it = map.find(value);
        if(it == map.end()) {
            l.push_front(value);
            s[value] = 1;
            map[value] = l.cbegin();
        }
        else if(s[value] != -1 && s[value] != 0) {
            l.erase(map[value]);
            s[value] = -1;
        }
        q.push(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */