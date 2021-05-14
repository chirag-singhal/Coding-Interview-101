## [Find And Replace in String](https://leetcode.com/problems/find-and-replace-in-string/)

### Problem Link - https://leetcode.com/problems/find-and-replace-in-string/

---

### Solution

```cpp

    class Solution {
    public:
        string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
            
            string ans = "";
            vector<pair<int, int>> p;
            
            for(int i = 0; i < indexes.size(); i++) {
                p.push_back(make_pair(indexes[i], i));
            }
            
            sort(p.begin(), p.end());
            int j = 0;
            
            for(int i = 0; i < s.length(); i++) {
                if(j >= p.size() || i != p[j].first)
                    ans += s[i];
                else {
                    int idx = s.find(sources[p[j].second], p[j].first);
                    if(idx != string::npos && idx == p[j].first) {
                        ans += targets[p[j].second];
                        i += sources[p[j].second].length() - 1;
                    }
                    else
                        ans += s[i];
                    j++;
                }
            }
            return ans;
        }
    };



```