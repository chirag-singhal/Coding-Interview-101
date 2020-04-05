#include <bits/stdc++.h>

int main() {
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++) {
        int n;
        std::cin>>n;
        long int arr[n];
        for(int j = 0; j < n; j++)
            std::cin>>arr[j];
        std::sort(arr, arr + n);
        long int sum = 0;
        for(int j = n - 1; j > -1; j--) {
            if(arr[j] + j - n + 1 > 0)
                sum += (arr[j] + j - n + 1) % 1000000007;
        }
        std::cout<<sum<<std::endl;
    }

    return 0;
}