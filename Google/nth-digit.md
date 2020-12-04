## [Nth Digit](https://leetcode.com/problems/nth-digit/)

### Problem Link - https://leetcode.com/problems/nth-digit/

---

### Solution

```cpp

    class Solution {
    public:
        int findNthDigit(int n) {
            if(n < 10)
                return n;
            int dig = 1;
            int num = 1;
            int count = 9;
            while((long)dig * (long)count <= (long)n) {
                n -= dig * count;
                dig++;
                count *= 10;
                num *= 10;
            }
            if(n == 0)
                return 9;
            while(dig <= n) {
                n -= dig;
                num++;
            }
            if(n == 0)
                return (num - 1) % 10;
            for(int i = 0; i < dig - n; i++) 
                num /= 10;
            return num % 10;
        }
    };

```