int trailingZeroes(int A) {
    int nfive = 0;
    for(int i = 5; i <= A; i++) {
        int a = i;
        while(a != 0 && a % 5 == 0) {
            nfive++;
            a /= 5;
        }
    }
    return nfive;
}
