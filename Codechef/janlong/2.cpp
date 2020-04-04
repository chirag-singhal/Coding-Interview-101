#include <iostream>

int main() {
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++) {
        unsigned long long int n, a, b, c, d, e, s;
        int res;
        std::cin>>n>>a;
        long long int ans = 1;
        for(int j = 0; j < n; j++)
            ans *= 10;
        
        s = 2 * ans + a;
        std::cout<<s<<std::endl;
        std::cin>>b;
        c = ans - b;
        std::cout<<c<<std::endl;
        std::cin>>d;
        e = ans - d;
        std::cout<<e<<std::endl;
        std::cin>>res;
        if(res == -1)
            break;
    }
    return 0;
}