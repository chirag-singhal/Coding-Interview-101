## Fruit Into Baskets

### Problem Link - https://leetcode.com/problems/fruit-into-baskets/

---

### Solution

```cpp

    class Solution {
        public:
            int totalFruit(vector<int>& tree) {
                int start = 0;
                int end = 0;
                int ans = 0;
                unordered_map<int, int> map;
                int diff = 0;
                while(end < tree.size()) {
                    if(map[tree[end]] == 0) {
                        diff++;
                    }
                    if(diff <= 2) {
                        map[tree[end]]++;
                        ans = max(ans, end - start + 1);
                        end++;
                    }
                    else {
                        while(diff != 2) {
                            map[tree[start]]--;
                            if(map[tree[start]] == 0)
                                diff--;
                            start++;
                        }
                        map[tree[end]]++;
                        ans = max(ans, end - start + 1);
                        end++;
                    }
                }
                return ans;
            }
        };
```