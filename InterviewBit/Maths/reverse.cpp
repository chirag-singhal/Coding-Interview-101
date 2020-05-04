int Solution::reverse(int A) {
    bool pos = true;
    if(A < 0) {
        pos = false;
        A = -A;
    }
    long int rev = 0;
    while(A != 0) {
        if(rev > INT_MAX)
            return 0;
        int rem = A % 10;
        rev = rev * 10 + (long)rem;
        A /= 10;
    }
    if(rev > INT_MAX)
        return 0;
    if(!pos)
        return (int)(-rev);
    else
        return (int)rev;
}
