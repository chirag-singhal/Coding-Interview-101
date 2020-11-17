class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        if(n == m)
            return n;
        while(n / 2 != 0 && m / 2 != 0) {
            int q1 = 1, q2 = 1;
            int n1 = n, m1 = m;
            while(n1 / 2 != 0) {
                q1 *= 2;
                n1 /= 2;
            }
            while(m1 / 2 != 0) {
                q2 *= 2;
                m1 /= 2;
            }
            if(q1 == q2)
                count += q1;
            else 
                break;
            n = n % q1;
            m = m % q2;
        }
        return count;
    }
};