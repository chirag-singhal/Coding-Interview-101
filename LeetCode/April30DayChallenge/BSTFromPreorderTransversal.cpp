#include <bits/stdc++.h>

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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* treeConstruction(std::vector<int>& preorder, int *index, int min, int max) {
        if(*index >= preorder.size())
            return NULL;
        
        TreeNode* x = NULL;
        
        if(preorder[*index] >= min && preorder[*index] <= max) {
            int key = preorder[*index];
            x = new TreeNode(key);
            *index += 1;
            
            x -> left = treeConstruction(preorder, index, min, key);
            x -> right = treeConstruction(preorder, index, key, max);
        }
        return x;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return treeConstruction(preorder, &index, INT_MIN, INT_MAX);
    }
};