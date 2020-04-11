#include <bits/stdc++.h>

int main() {
    int t;
    std::cin>>t;
    for( int i = 0; i < t; i++) {
        int n;
        std::cin>>n;
        bool arr[n];
        for(int j = 0; j < n; j++)
            arr[j] = 0;
        int brr[n / 2][n];
        for(int j = 0; j < n / 2; j++)
            brr[j][0] = 0;
        for(int j = 2; j <= n; j++) {
            if(arr[j] == 0) {
                int m = 0;
                for(int k = j; k <= n; k += j) {
                    if(arr[k] == 0) {
                        brr[m][0]++;
                        int l = brr[m][0];
                        brr[m++][l] = k;
                        arr[k] = 1;
                    }
                }
            }
        }
        std::cout<<n / 2<<std::endl;
        for(int j = 0; j < n / 2; j++) {
            if(j == 0) {
                std::cout<<++brr[j][0]<<" "<<1<<" ";
                for(int k = 1; k < brr[j][0]; k++) {
                    std::cout<<brr[j][k]<<" ";
                }
                std::cout<<std::endl;
                continue;
            }
            for(int k = 0; k <= brr[j][0]; k++) 
                std::cout<<brr[j][k]<<" ";
            std::cout<<std::endl;
        }
    }
    return 0;
}