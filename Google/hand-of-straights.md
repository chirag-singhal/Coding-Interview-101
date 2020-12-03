## [Hand of Straights](https://leetcode.com/problems/hand-of-straights/)

### Problem Link - https://leetcode.com/problems/hand-of-straights/

> Note: This question is the same as 1296: <https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/>

---

### Solution

```cpp

    class Solution {
    public:
        bool isNStraightHand(vector<int>& hand, int W) {
            if(hand.size() % W != 0)
                return false;
            map<int, int> freq;
            for(int i = 0; i < hand.size(); i++)
                freq[hand[i]]++;
            for(auto it = freq.begin(); it != freq.end(); it++) {
                int count = it -> second;
                int ele = it -> first;
                auto ij = it;
                if(count == 0)
                    continue;
                for(int j = 0; j < W; j++, ij++) {
                    if(ele + j != ij -> first)
                        return false;
                    if(count > ij -> second)
                        return false;
                    freq[ele + j] -= count;
                }
            }
            return true;
        }
    };

```