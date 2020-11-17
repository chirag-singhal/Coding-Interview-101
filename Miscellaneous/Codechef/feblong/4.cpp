#include <iostream>
#include <bits/stdc++.h>

int main() {
    int t;
    std::cin>>t;
    for(int k = 0; k < t; k++) {
        long int n, p;
        std::cin>>n>>p;
        int arr[n], brr[n];
        for(int j = 0; j < n; j++)
            std::cin>>arr[j];
        int flag = 1;
        for(int i = 0; i < n; i++)
            brr[i] = 0;
        for(int i = 0; i < n - 1; i++)
            if(arr[i + 1] % arr[i] != 0)
                flag = 0;
        if(flag == 1 && p % arr[n - 1] == 0)
            printf("NO\n");
        else {
            for(int i = n - 1; i > -1; i--) {
                if(p % arr[i] != 0) {
                    brr[i] = p / arr[i] + 1;
                    p -= brr[i] * arr[i];
                    break;
                }
                else {
                    brr[i] = p / arr[i] - 1;
                    p -= brr[i] * arr[i];
                }
            }
            printf("YES ");
            for(int i = 0; i < n; i++)
                printf("%d ", brr[i]);
            putchar('\n');   
        }
    }
}