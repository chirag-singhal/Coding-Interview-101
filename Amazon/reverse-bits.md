## [Reverse Bits](https://leetcode.com/problems/reverse-bits/)

### Problem Link - https://leetcode.com/problems/reverse-bits/

---

### Solution

```cpp

    class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            uint32_t ans = 0;
            for(int i = 0; i < 32; i++) {
                int temp = (n >> i) & 1;
                ans |= temp << (31 - i);
            }
            return ans;
        }
    };

```