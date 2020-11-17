#include <bits/stdc++.h>

int main() {
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++) {
        int n;
        std::cin>>n;
        int x_prev = -1, x_curr;
        int count = 1, min = INT_MAX, max = INT_MIN;

        for(int j = 0; j < n; j++) {
            if(x_prev == -1) {
                std::cin>>x_prev;
                continue;
            }
            std::cin>>x_curr;
            if(x_curr - x_prev < 3) {
                count++;
                x_prev = x_curr; 
            }
            else {
                if(count < min)
                    min = count;
                if(count > max)
                    max = count;
                count = 1;
                x_prev = x_curr;
            }
        }

        if(count < min)
            min = count;
        if(count > max)
            max = count;

        std::cout<<min<<" "<<max<<"\n";
    }
    return 0;
}