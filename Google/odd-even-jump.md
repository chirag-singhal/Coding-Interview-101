## Odd Even Jump

### Problem Link - https://leetcode.com/problems/odd-even-jump/

---

### Solution

```cpp

    class Solution {
        public:
            int oddEvenJumps(vector<int>& A) {
                int n = A.size();
                vector<vector<bool>> a(n, vector<bool> (2, false));
                
                map<int, int> m;
                int count = 1;
                
                a[n - 1] = { true, true };
                m[A[n - 1]] = n - 1;
                
                for(int i = n - 2; i >= 0; i--) {
                auto it = m.lower_bound(A[i]);
                if(it != m.end()) {  
                        if(a[it -> second][0]) {
                            a[i][1] = true;
                            count++;
                        }
                        if(it -> first == A[i]) {
                            a[i][0] = a[it -> second][1];
                        }
                        else if(it != m.begin()) {
                            it--;
                            a[i][0] = a[it->second][1];
                        }
                    }
                    else {
                        it--;
                        a[i][0] = a[it -> second][1];
                    }
                    m[A[i]] = i;
                }
                return count;
            }
        };
```