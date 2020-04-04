#include <bits/stdc++.h>

int main() {
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++) {
        long long int n, k, count = 0;
        std::cin>>n>>k;
        long long int brr[n], crr[n];
        long long int arr[n];
        for(int j = 0; j < n; j++) {
            std::cin>>arr[j];
        }
        for(int l = 0; l < n; l++){
            int c = 0, c1 = 0;
            for(int j = 0; j < n; j++) {
                if(arr[l] > arr[j]){
                    c++;
                    if(j > l)
                        c1++;
               }
           }
           brr[l] = c;
           crr[l] = c1;
        }
        for(int j = 0; j < n; j++){
            // std::cout<<j<<std::endl;
            count += ((k * (k - 1)) / 2) * brr[j] + k * crr[j];
            // std::cout<<count<<std::endl;
        }
        std::cout<<count<<std::endl;
    }
    return 0;
}
