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
    bool isValidSequence(TreeNode* root, std::vector<int>& arr) {
        return state(root, arr, 0) == arr.size();
    }
    int max(int a, int b) {
        if(a > b)
            return a;
        return b;
    }
    int state(TreeNode* root, std::vector<int>& arr, int s) {
        if(root != NULL && root -> val == arr[s] && s == arr.size() - 1 && root -> left == NULL && root -> right == NULL)
            return s + 1;
        if(s == arr.size() - 1)
            return 0;
        if(root == NULL)
            return 0;
        if(root -> val == arr[s]) {
            s += 1;
            return max(state(root -> left, arr, s), state(root -> right, arr, s));
        }
        else {
            return 0;    
        }
    }
};