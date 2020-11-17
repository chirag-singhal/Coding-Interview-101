#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int height = 0;
        return diameter(root, &height);
    }
    
    int diameter(TreeNode* root, int * height) {
        int lh = 0, rh = 0;
        
        if(root == NULL) {
            *height = 0;
            return 0;
        }
        
        int ld = diameter(root -> left, &lh);
        int rd = diameter(root -> right, &rh);
        
        *height = max(lh, rh) + 1;
        
        return max(max(lh + rh, ld), rd);
    }
    
    int max(int a, int b) {
        if(a > b)
            return a;
        else
            return b;
    }
};