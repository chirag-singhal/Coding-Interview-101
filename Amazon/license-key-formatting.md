## [License Key Formatting](https://leetcode.com/problems/license-key-formatting/)

### Problem Link - https://leetcode.com/problems/license-key-formatting/

---

### Solution

```cpp

    class Solution {
    public:
        string licenseKeyFormatting(string S, int K) {
            string ans = "";
            int count = 0;
            string temp = "";
            for(int i = S.length() - 1; i >= 0; i--) {
                if(S[i] != '-')
                    count++;
            }
            int i = 0;
            int added = 0;
            for(; i < S.length(); i++) {
                if(S[i] == '-')
                    continue;
                else if(S[i] >= 'a' && S[i] <= 'z') 
                    ans += (char)(S[i] + 'A' - 'a');
                else
                    ans += S[i];
                added++;
                if(added == count % K || added == K)
                    break;
            }
            added = 0;
            i++;
            for(; i < S.length(); i++) {
                if(S[i] == '-')
                    continue;
                else if(S[i] >= 'a' && S[i] <= 'z') 
                    temp += (char)(S[i] + 'A' - 'a');
                else
                    temp += S[i];
                added++;
                if(added == K) {
                    ans += '-' + temp;
                    temp = "";
                    added = 0;
                }
            }
            return ans;
        }
    };

```