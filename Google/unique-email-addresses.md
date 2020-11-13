## Unique Email Addresses

### Problem Link - https://leetcode.com/problems/unique-email-addresses/

---

### Solution

```cpp

    class Solution {
    public:
        int numUniqueEmails(vector<string>& emails) {
            unordered_map<string, int> map;
            int ans = 0;
            for(int i = 0; i < emails.size(); i++) {
                string name = "";
                string dom = "";
                int j = 0;
                while(emails[i][j] != '@') {
                    if(emails[i][j] == '.') {
                        j++;
                        continue;
                    } 
                    else if(emails[i][j] == '+') {
                        break;
                    }
                    else {
                        name += emails[i][j];
                        j++;
                    }
                }
                while(emails[i][j] != '@') {
                    j++;
                }
                j++;
                while(j < emails[i].length()) {
                    dom += emails[i][j];
                    j++;
                }
                if(map[name + '@' + dom] == 0) {
                    ans++;
                    map[name + '@' + dom]++;
                }
            }
            return ans;
        }
    };
```