## [Word Ladder](https://leetcode.com/problems/word-ladder/)

### Problem Link - https://leetcode.com/problems/word-ladder/

---

### Solution

```cpp
    class Solution {
    public:
        bool oneLetterTransformataion(string a, string b) {
            int diff = 0;
            for(int i = 0; i < a.length(); i++) {
                if(a[i] != b[i])
                    diff++;
            }
            return diff == 1;
        }
        
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            int n = wordList.size();
            int ans = 0;
            unordered_map<string, int> vis;
            unordered_map<string, int> dict;
            unordered_map<string, vector<string>> adj;
            if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
                return 0;
            }
            
            for(int i = 0; i < n; i++) {
                dict[wordList[i]] = 1; 
            }
            
            queue<string> q;
            q.push(beginWord);
            vis[beginWord] = 1;

            while(!q.empty()) {
                int size = q.size();
                ans++;
                while(size) {
                    string s = q.front();
                    if(s == endWord) {
                        return ans;
                    }
                    vis[s] = 1;
                    q.pop();
                    for(int i = 0; i < s.length(); i++) {
                        char temp = s[i];
                        for(int j = 0; j < 26; j++) {
                            if(s[i] == j + 'a') 
                                continue;
                            s[i] = j + 'a';
                            if(dict[s] == 1 && vis[s] == 0) {
                                vis[s] = 1;
                                q.push(s);
                            }
                        }
                        s[i] = temp;
                    }
                    size--;
                }
            }
            return 0;
        }
    };
    
```