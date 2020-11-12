## Odd Even Jump

### Porblem Link - https://leetcode.com/problems/odd-even-jump/

---

### Solution

    class Solution {
        public:
            int oddEvenJumps(vector<int>& A) {
                int n = A.size();
                vector<vector<bool>> res(n, vector<bool> (2, false));
                
                map<int, int> m;
                int count = 1;
                
                res[n - 1] = { true, true };
                m[A[n - 1]] = n - 1;
                
                for(int i = n - 2; i >= 0; i--) {
                auto it = m.lower_bound(A[i]);
                if(it != m.end()) {  
                        if(res[it -> second][0]) {
                            res[i][1] = true;
                            count++;
                        }
                        if(it -> first == A[i]) {
                            res[i][0] = res[it -> second][1];
                        }
                        else if(it != m.begin()) {
                            it--;
                            res[i][0] = res[it->second][1];
                        }
                    }
                    else {
                        it--;
                        res[i][0] = res[it -> second][1];
                    }
                    m[A[i]] = i;
                }
                return count;
            }
        };