## [Course Schedule](https://leetcode.com/problems/course-schedule/)

### Problem Link - https://leetcode.com/problems/course-schedule/

---

### Solution

```cpp

    class Solution {
    public:
        bool checkLoop(vector<int>& vis, int i, unordered_map<int, vector<int>>& adj) {
            bool f = false;
            for(int j = 0; j < adj[i].size(); j++) {
                if(vis[adj[i][j]] == 1) {
                    return true;
                }
                else if(vis[adj[i][j]] == 0) {
                    vis[adj[i][j]] = 1;
                    f = checkLoop(vis, adj[i][j], adj);
                    if(f == true)
                        break;
                }
            }
            vis[i] = 2;
            return f;
        }
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            unordered_map<int, vector<int>> adj;
            vector<int> vis(numCourses, 0);
            for(int i = 0; i < prerequisites.size(); i++) {
                adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            }
            for(int i = 0; i < numCourses; i++) {
                if(vis[i] == 0) {
                    vis[i] = 1;
                    if(checkLoop(vis, i, adj))
                        return false;
                }
            }
            return true;
        }
    };

```