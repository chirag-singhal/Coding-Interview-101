class Solution {
public:
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = squareSum(slow);             //same method as checking loop in a linked list
            fast = squareSum(squareSum(fast));
        } while(slow != fast);
        
        return (slow == 1);
    }
    
    int squareSum(int n) {
        int sum = 0;
        
        while(n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        
        return sum;
    }
};