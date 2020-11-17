## [Clone Graph](https://leetcode.com/problems/clone-graph/)

### Problem Link - https://leetcode.com/problems/clone-graph/

---

### Solution

```cpp

    /*
    // Definition for a Node.
    class Node {
    public:
        int val;
        vector<Node*> neighbors;
        
        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }
        
        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }
        
        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    };
    */

    class Solution {
    public:
        Node* cloneGraph(Node* node) {
            if(node == NULL)
                return NULL;
            
            queue<Node*> q1;
            queue<Node*> q2;
            unordered_map<int, int> vis;
            unordered_map<int, Node*> map;

            
            Node* ans = new Node(node -> val);
            vis[node -> val] = 1;
            map[node -> val] = ans;

            for(int i = 0; i < node -> neighbors.size(); i++) {
                Node* temp = new Node(node -> neighbors[i] -> val);
                map[temp -> val] = temp;
                ans -> neighbors.push_back(temp);
                q1.push(node -> neighbors[i]);
                q2.push(temp);
            }
            while(!q1.empty()) {
                Node* temp1 = q1.front();
                Node* temp2 = q2.front();
                q1.pop();
                q2.pop();
                if(vis[temp1 -> val] == 0) {
                    for(int i = 0; i < temp1 -> neighbors.size(); i++) {
                        Node* temp;
                        if(map[temp1 -> neighbors[i] -> val] == NULL) {
                            temp = new Node(temp1 -> neighbors[i] -> val);
                            map[temp -> val] = temp;
                        }
                        else
                            temp = map[temp1 -> neighbors[i] -> val];
                        temp2 -> neighbors.push_back(temp);
                        q1.push(temp1 -> neighbors[i]);
                        q2.push(temp);
                    }
                }
                vis[temp1 -> val] = 1;
            }
            return ans;
        }
    };
```