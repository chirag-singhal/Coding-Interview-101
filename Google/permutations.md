## [Permutations](https://leetcode.com/problems/permutations/)

### Problem Link - https://leetcode.com/problems/permutations/

---

### Solution

```cpp

    class Solution {
    public:
        void perm(vector<vector<int>>& ans, vector<int>& nums, int idx) {
            if(idx == nums.size() - 1)
                ans.push_back(nums);
            else {
                for(int i = idx; i < nums.size(); i++) {
                    swap(nums[i], nums[idx]);
                    perm(ans, nums, idx + 1);
                    swap(nums[i], nums[idx]);
                }
            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ans;
            perm(ans, nums, 0);
            return ans;
        }
    };

```