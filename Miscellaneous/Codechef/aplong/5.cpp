#include <bits/stdc++.h>

int main() {
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++) {
        int n, m, k;
        std::cin>>n>>m>>k;
        int sol[n][k];
        int ans[n];
        for(int j = 0; j < n; j++) {
            int max = 0;
            int count[m];
            int probans = 0;
            for(int l = 0; l < m; l++) 
                count[l] = 0;
            for(int l = 0; l < k; l++) {
                std::cin>>sol[j][l];
                count[sol[j][l]]++;
                if(count[sol[j][l]] > max) {
                    max = count[sol[j][l]];
                    probans = sol[j][l];
                }
            }
            ans[j] = probans;
        }
        for(int j = 0; j < n; j++) 
            std::cout<<ans[j]<<" ";
        std::cout<<std::endl;
    }
    return 0;
}