#include <iostream>
#include <bits/stdc++.h>

int main() {
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++) {
        int n;
        std::cin>>n;
        long int arr[n], brr[n];
        for(int j = 0; j < n; j++)
            std::cin>>arr[j];
        for(int j = 0; j < n; j++)
            std::cin>>brr[j];
        std::sort(arr, arr + n);
        std::sort(brr, brr + n);
        long long int sum = 0;
        for(int j = 0; j < n; j++) {
            if(arr[j] < brr[j])
                sum += arr[j];
            else 
                sum += brr[j];
        }
        std::cout<<sum<<std::endl;
    }
    return 0;
}