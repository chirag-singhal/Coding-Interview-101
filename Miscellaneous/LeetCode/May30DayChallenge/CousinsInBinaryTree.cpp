#include <bits/stdc++.h>

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool isSibling(TreeNode* root, int x, int y) {
        if(root == NULL)
            return false;
        if(root -> left == NULL)
            return isSibling(root -> right, x, y);
        if(root -> right == NULL)
            return isSibling(root -> left, x, y);
        if((root -> left -> val == x && root -> right -> val == y) || (root -> left -> val == y && root -> right -> val == x))
            return true;
        bool a = isSibling(root -> left, x, y);
        if(a == true)
            return a;
        return isSibling(root -> right, x, y);
    }
    int level(TreeNode* root, int x, int l) {
        if(root == NULL)
            return 0;
        if(root -> val == x)
            return l;
        int l1 = level(root -> right, x, l + 1);
        if(l1 != 0) 
            return l1;
        return level(root -> left, x, l + 1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        return level(root, x, 0) == level(root, y, 0) && !isSibling(root, x, y);
    }
};