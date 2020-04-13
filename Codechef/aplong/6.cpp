#include <bits/stdc++.h>

int main() {
    int t;
    std::cin>>t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin>>n;
        int arr[n];
        int num;
        for(int j = 0; j < n; j++) {
            std::cin>>num;
            if(num % 2 == 1)
                arr[j] = 0;
            else if(num % 4 == 0)
                arr[j] = 1;
            else
                arr[j] = 2;
        }
    }

    return 0;
}