int gcd(int a, int b) {
    if(a == 0 || b == 0)
        return 0;
    if(a == b)
        return a;
    if(a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

int cpFact(int A, int B) {
    int g = gcd(A, B);
    while(g != 1) {
        A /= g;
        g = gcd(A, B);
    }
    return A;
}
