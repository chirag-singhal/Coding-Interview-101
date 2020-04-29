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
    int max(int a, int b) {
        if(a > b)
            return a;
        return b;
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        maxSum(root, &sum);    
        return sum;
    }
    int maxSum(TreeNode* root, int* sum) {
        if(root == NULL)
            return 0;
        
        int lmax = maxSum(root -> left, sum);
        int rmax = maxSum(root -> right, sum);
        int max_lrv = max(max(lmax, rmax) + root -> val, root -> val);
        int max_inc = max(max_lrv, lmax + rmax + root -> val);
        
        *sum = max(max_inc, *sum);
        
        return max_lrv;
    }
};