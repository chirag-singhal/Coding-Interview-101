## Two Sum

### Problem Link - https://leetcode.com/problems/two-sum/

---

### Solution

    class Solution {
        public:
            vector<int> twoSum(vector<int>& nums, int target) {
                unordered_map<int, int> map;
                vector<int> ans;
                for(int i = 0; i < nums.size(); i++) {
                    if(map[target - nums[i]] != 0) {
                        ans.push_back(map[target - nums[i]] - 1);
                        ans.push_back(i);
                    }
                    map[nums[i]] = i + 1;
                }
                return ans;
            }
        };
    