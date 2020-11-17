## [Word Ladder II](https://leetcode.com/problems/word-ladder-ii/)

### Problem Link - https://leetcode.com/problems/word-ladder-ii/

---

### Solution

```cpp

    class Solution {
    public:
        bool back(unordered_map<string, vector<string>>& adj, string A, vector<string>& temp, int level, int min, vector<vector<string>>& ans, string endWord, unordered_map<string, int>& vis) {
            temp[level] = A;
            if(level == min - 1 && A == endWord) {
                ans.push_back(temp);            
                return true;
            }
            else if(level == min - 1) {
                return false;
            }
            for(int i = 0; i < adj[A].size(); i++) {
                if(vis[adj[A][i]] == 0) {
                    vis[adj[A][i]] = 1;
                    back(adj, adj[A][i], temp, level + 1, min, ans, endWord, vis);
                    vis[adj[A][i]] = 0;
                }
            }
            return true;
        }
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
                int n = wordList.size();
                vector<vector<string>> ans;
                int min = 0; 
                unordered_map<string, int> dict;
                unordered_map<string, int> vis;
                unordered_map<string, vector<string>> adj;
                if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
                    return ans;
                }
                
                for(int i = 0; i < n; i++) {
                    dict[wordList[i]] = 1; 
                }
                
                queue<string> q;
                q.push(beginWord);
                dict[beginWord] = 0;
                bool done = false;

                while(!q.empty() && !done) {
                    int size = q.size();
                    min++;                    
                    vector<string> t;
                    while(size) {
                        string s = q.front();
                        string scopy = q.front();
                        if(s == endWord) {
                            done = true;
                            break;
                        }
                        dict[s] = 0;
                        q.pop();
                        for(int i = 0; i < s.length(); i++) {
                            char temp = s[i];
                            for(int j = 0; j < 26; j++) {
                                if(s[i] == j + 'a') 
                                    continue;
                                s[i] = j + 'a';

                                if(vis[s] == 0 && dict[s] == 1) {
                                    t.push_back(s);
                                    vis[s] = 1;
                                    q.push(s);
                                    adj[scopy].push_back(s);
                                }
                                else if(dict[s] == 1) {
                                    adj[scopy].push_back(s);
                                }
                                else if(s == endWord) {
                                    adj[scopy].push_back(s);
                                }
                            }
                            s[i] = temp;
                        }
                        size--;
                    }
                    for(int i = 0; i < t.size(); i++)
                        dict[t[i]] = 0;
                }
                if(!done)
                    return ans;
                vector<string> temp(min); 
                unordered_map<string, int> tem;
                tem[beginWord] = 1;
                back(adj, beginWord, temp, 0, min, ans, endWord, tem);
                return ans;
        }
    };
    
```