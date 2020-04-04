#include <bits/stdc++.h>

int main() {
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++) {
       int n;
       std::cin>>n;
       int arr[n];
       for(int j = 0; j < n; j++) {
           std::cin>>arr[j];
       }
       std::sort(arr, arr + n);
    //   for(int j = 0; j < n; j++) {
    //       std::cout<<arr[j];
    //   }
        int found = 1;
        for(int j = 1; j < 4; j++) {
            if(arr[(n / 4) * j - 1] == arr[(n / 4) * j]) {
                found = 0;
                break;
            }
        }
        if(found) {
            for(int j = 1; j < 4; j++) {
                std::cout<<arr[(n / 4) * j]<<" ";
            }
        }
        else {
            std::cout<<-1;
        }
        std::cout<<std::endl;
    }
    return 0;
}
