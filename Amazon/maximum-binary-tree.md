## [Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/)

### Problem Link - https://leetcode.com/problems/maximum-binary-tree/

---

### Solution

```cpp

    /**
    * Definition for a binary tree node.
    * struct TreeNode {
    *     int val;
    *     TreeNode *left;
    *     TreeNode *right;
    *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    * };
    */
    class Solution {
    public:
        TreeNode* constructMaximumBinaryTreeUtil(vector<int>& nums, int lo, int hi) {
            if(lo > hi)
                return NULL;
            int max = INT_MIN;
            int maxIdx = lo;
            for(int i = lo; i <= hi; i++) {
                if(max < nums[i]) {
                    max = nums[i];
                    maxIdx = i;
                }
            }
            TreeNode* left = constructMaximumBinaryTreeUtil(nums, lo, maxIdx - 1);
            TreeNode* right = constructMaximumBinaryTreeUtil(nums, maxIdx + 1, hi);
            TreeNode* node = new TreeNode(max, left, right);
            return node;
        }
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            return constructMaximumBinaryTreeUtil(nums, 0, nums.size() - 1);
        }
    };

```