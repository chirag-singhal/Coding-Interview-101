#include <bits/stdc++.h>

int main() {
    int t;
    std::cin>>t;
    for( int k = 0; k < t; k++) {
        int n;
        std::cin>>n;
        if(n == 1) {
            std::cout<<1<<std::endl;
            std::cout<<1<<" "<<1<<std::endl;
            continue;
        }
        else {
            int l = n / 2;
            std::cout<<l<<std::endl;

            for(int i = 2; i <= n; i++) {
                if(i != 2 && i + 1 <= n) 
                    std::cout<<2<<" "<<i++<<" "<<i<<std::endl;
                else if (i != 2)
                    std::cout<<1<<" "<<i++<<std::endl;
                else if(i == 2 && i + 1 <= n) 
                    std::cout<<3<<" "<<1<<" "<<i++<<" "<<i<<std::endl;
                else if(i == 2) 
                    std::cout<<2<<" "<<1<<" "<<i++<<std::endl;
            }
        }
    }
    return 0;
}