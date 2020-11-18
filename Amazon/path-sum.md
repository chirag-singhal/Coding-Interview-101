## [Path Sum](https://leetcode.com/problems/path-sum/)

### Problem Link - https://leetcode.com/problems/path-sum/

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
        bool hasPathSum(TreeNode* root, int sum) {
            if(root == NULL)
                return false;
            if(sum - root -> val == 0 && root -> left == NULL && root -> right == NULL)
                return true;
            return hasPathSum(root -> left, sum - root -> val) || hasPathSum(root -> right, sum - root -> val);
        }
    };

```