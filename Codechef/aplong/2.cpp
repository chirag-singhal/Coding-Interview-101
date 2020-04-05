#include <bits/stdc++.h>

int main() {
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++) {
        int n;
        int soc_dist = 1;
        int lastperson = -1;
        std::cin>>n;
        long int arr[n];
        for(int j = 0; j < n; j++) {
            std::cin>>arr[j];
            if(lastperson == -1 && arr[j] == 1)
                lastperson = j;
            else if (arr[j] == 1) {
                if(j - lastperson < 6)
                    soc_dist = 0;
                lastperson = j;
            }
        }
        if(soc_dist)
            std::cout<<"YES"<<std::endl;   
        else
            std::cout<<"NO"<<std::endl;
    }

    return 0;
}