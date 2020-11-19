## [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

### Problem Link - https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            stack<vector<int>> s;
            vector<vector<int>> ans;
            if(root == NULL)
                return ans;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()) {
                int size = q.size();
                vector<int> temp;
                while(size) {
                    TreeNode* top = q.front();
                    q.pop();
                    temp.push_back(top -> val);
                    if(top -> left)
                        q.push(top -> left);
                    if(top -> right)
                        q.push(top -> right);
                    size--;
                }
                s.push(temp);
            }
            while(!s.empty()) {
                ans.push_back(s.top());
                s.pop();
            }
            return ans;
        }
    };

```