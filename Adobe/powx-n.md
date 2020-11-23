## [Pow(x, n)](https://leetcode.com/problems/powx-n/)

### Problem Link - https://leetcode.com/problems/powx-n/

---

### Solution

```cpp

    class Solution {
    public:
        double pow(double x, int n) {
            if(n == 0)
                return 1;
            if(n == 1)
                return x;
            double temp = pow(x, n / 2);
            if(n % 2 == 0)
                return temp * temp;
            else 
                return temp * temp * x;
        }
        double myPow(double x, int n) {
            if(n >= 0)
                return pow(x, abs(n));
            else 
                return 1 / pow(x, abs(n));
        }
    };

```