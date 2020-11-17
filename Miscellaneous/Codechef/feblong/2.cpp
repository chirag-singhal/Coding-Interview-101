#include <iostream>
#include <bits/stdc++.h>

int main() {
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++) {
        long int n, k, max = 0;
        std::cin>>n>>k;
        long int arr[n], brr[n], crr[n];
        for(long int j = 0; j < n; j++) {
            std::cin>>arr[j];
            brr[j] = 0;
            if(arr[j] % k != 0){
                max = j + 1;
                brr[j] = k - arr[j] % k;
            }
        }
        long long int sum = 0;
        for(long int j = n - 1; j != -1; j--) {
            sum += brr[j];
            crr[j] = sum;
        }
        if(max == 0) {
            std::cout<<0<<std::endl;
            continue;
        }
        long long int c = 0, j = 0;
        for(j = 0; j < max; j++) {
            if(c >= crr[j]){
                sum = 0;
                break;
            }
            c += arr[j] % k;
            // std::cout<<c<<' ';
        }
        if(sum == 0)
            std::cout<<c - crr[j]<<std::endl;
        else 
            std::cout<<c<<std::endl;
    }
    return 0;
}