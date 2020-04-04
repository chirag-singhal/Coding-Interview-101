#include <iostream>

int main() {
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++) {
        int n, m;
        std::cin>>n>>m;
        long int arr[n][m];
        for(int j = 0; j < n; j++)
            for(int k = 0; k < m; k++)
                std::cin>>arr[j][k];
        int less = n > m ? m : n;
        bool brr[n][m][less];

        for(int k = 0; k < n; k++)
            for(int j = 0; j < m; j++)
                for(int l = 0; l < less; l++)
                    brr[k][j][l] = 0;
        
        for(int k = 0; k < n; k++)
            for(int j = 0; j < m; j++)
                brr[k][j][1] = 1;

        long long int ans = m * n;
        for(int l = 3; l <= n && l <= m; l += 2) {
            for(int j =  l / 2; j < n - l / 2; j++) {
                for(int k = l / 2; k < m - l / 2; k++) {
                    // std::cout<<j<<" "<<k<<std::endl;
                    // std::cout<<arr[j + l - 2][k]<<"   "<<arr[j - l + 2][k]<<std::endl;
                    // std::cout<<arr[j][k + l - 2]<<"   "<<arr[j][k - l + 2]<<std::endl;
                    if(brr[j][k][l - 2] && arr[j + l / 2][k] == arr[j - l / 2][k] && arr[j][k + l / 2] == arr[j][k - l / 2] ) {
                        ans++;
                        // std::cout<<j<<"  "<<k<<" "<<l<<" "<<ans<<std::endl;
                        brr[j][k][l] = 1;
                    }

                }
            }
        }
        std::cout<<ans<<std::endl;
    }
    return 0;
}