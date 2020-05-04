int gcd(int A, int B) {
    if(A == 0 )
        return B;
    else if(B == 0)
        return A;
    int dd, ds;
    if(A > B) {
        dd = A;
        ds = B;
    }
    else {
        dd = B;
        ds = A;
    }
    int rem = dd % ds;
    while(rem != 0) {
        dd = ds;
        ds = rem;
        rem = dd % ds;
    }
    return ds;
}
