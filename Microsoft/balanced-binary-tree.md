## [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

### Problem Link - https://leetcode.com/problems/balanced-binary-tree/

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
        bool isBal(TreeNode* root, int* h) {
            if(root == NULL) {
                *h = 0;
                return true;
            }
            int lh, rh;
            bool lb = isBal(root -> left, &lh);
            bool rb = isBal(root -> right, &rh);
            *h = max(lh, rh) + 1;
            if(!lb || !rb || abs(lh - rh) > 1)
                return false;
            return true;
        }
        bool isBalanced(TreeNode* root) {
            int height = 0;
            return isBal(root, &height);
        }
    };

```