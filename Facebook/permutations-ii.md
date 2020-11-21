## [Permutations II](https://leetcode.com/problems/permutations-ii/)

### Problem Link - https://leetcode.com/problems/permutations-ii/

---

### Solution

```cpp

   class Solution {
    public:
        bool check(vector<int>& nums, int idx, int curr) {
            for (int i = idx; i < curr; i++) 
                if (nums[i] == nums[curr])
                    return 0;
            return 1;
        }
        void perm(vector<vector<int>>& ans, vector<int>& nums, int idx) {
            if(idx == nums.size() - 1) {
                ans.push_back(nums);
            }
            else {
                for(int i = idx; i < nums.size(); i++) {
                    if(check(nums, idx, i)) {
                        swap(nums[i], nums[idx]);
                        perm(ans, nums, idx + 1);
                        swap(nums[i], nums[idx]);
                    }
                }
            }
        }
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int>> ans;
            perm(ans, nums, 0);
            return ans;
        }
    };

```