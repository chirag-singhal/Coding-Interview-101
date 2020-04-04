#include <bits/stdc++.h>

int main() {
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++) {
        long long int n, k;
        std::cin>>n>>k;
        long long int arr[n], brr[n], crr[n], drr[n];
        for(int j = 0; j < n; j++) {
            std::cin>>drr[j];
        }
        for(int  a = 0; a < k; a++) {
            long long int count = 0;
            long long int realK;
            std::cin>>realK;
            for(int j = 0; j < n; j++) {
                arr[j] = drr[j] ^ realK;
            }
            // for(int j = 0; j < n; j++) {
            //     std::cout<<arr[j];
            // }
            for(int l = 0; l < n; l++){
                for(int j = l + 1; j < n; j++) {
                    if(arr[l] > arr[j]){
                        count++;
                   }
               }
            }
            std::cout<<count<<std::endl;
        }
    }
    return 0;
}
