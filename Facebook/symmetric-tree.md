## [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)

### Problem Link - https://leetcode.com/problems/symmetric-tree/

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
        bool isMirror(TreeNode* A, TreeNode* B) {
            if(A == NULL && B == NULL)
                return true;
            if(A == NULL || B == NULL)
                return false;
            return A -> val == B -> val &&  isMirror(A -> left, B -> right) 
                && isMirror(A -> right, B -> left);
                
        }
        bool isSymmetric(TreeNode* root) {
            return isMirror(root, root);
        }
    };

```