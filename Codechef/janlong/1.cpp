#include <iostream>

int main() {
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++) {
        int s, w1, w2, w3;
        std::cin>>s>>w1>>w2>>w3;
        if(w1 + w2 + w3 <= s)
            std::cout<<1<<std::endl;
        else if(w1 + w2 <= s) 
            std::cout<<2<<std::endl;
        else if(w2 + w3 <= s)
            std::cout<<2<<std::endl;
        else 
            std::cout<<3<<std::endl;
    }
    return 0;
}