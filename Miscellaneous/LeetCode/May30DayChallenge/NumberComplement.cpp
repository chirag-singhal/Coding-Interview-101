class Solution {
public:
    int findComplement(int num) {
        if(num == 0)
            return 1;
        long int k = 1;
        int n = num;
        while(n != 0) {
            k *= 2;
            n /= 2;
        }
        int A = k - 1;
        return (num ^ A);
    }
};