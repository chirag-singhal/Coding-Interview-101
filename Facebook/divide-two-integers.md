## [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/)

### Problem Link - https://leetcode.com/problems/divide-two-integers/

---

### Solution

```cpp

    class Solution {
    public:
        int divide(int dividend, int divisor) {
            if(dividend == 0)
                return 0;
            if(divisor == 1)
                return dividend;
            long int quotient = 0;
            int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
            if(divisor == -1 && dividend == INT_MIN)
                return INT_MAX;
            if(divisor == -1)
                return sign * abs(dividend);
            long int divid = abs(dividend);
            long int divis = abs(divisor);
            for(int i = 31; i >= 0; i--) {
                if(divid - (divis << i) >= 0) {
                    divid -= (divis << i);
                    quotient |= (1 << i);
                }
            }
            if(sign * quotient > INT_MAX || sign * quotient < INT_MIN)
                return INT_MAX;
            return sign * quotient;
        }
    };

```