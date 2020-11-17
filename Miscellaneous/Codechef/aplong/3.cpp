#include <bits/stdc++.h>

int main() {
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++) {
        long int x, k;
        std::cin>>x>>k;
        long int count = 0;
        while(x % 2 == 0) {
            count++;
            x /= 2;
        }
        for(long int i = 3; i <= sqrt(x); i += 2) 
            while(x % i == 0) {
                count++;
                x /= i;
            }
        if(x > 2)
            count++;
        if(count >= k)
            std::cout<<1<<std::endl;
        else
            std::cout<<0<<std::endl;
    }

    return 0;
}