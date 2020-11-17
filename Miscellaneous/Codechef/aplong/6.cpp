#include <bits/stdc++.h>

int main() {
    int t;
    std::cin>>t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin>>n;
        int arr[n];
        int even[n + 1], four[n + 1];
        long long int num;
        int k1 = 0, k2 = 0;
        for(int j = 0; j < n; j++) {
            std::cin>>num;
            if(num % 2 == 0)
                even[k1++] = j;
            if(num % 4 == 0)
                four[k2++] = j;
            if(num % 2 == 1)
                arr[j] = 0;
            else if(num % 4 == 0)
                arr[j] = 1;
            else
                arr[j] = 2;
        }
        while(k1 < n + 1)
            even[k1++] = -1;
        while(k2 < n + 1)
            four[k2++] = -1;

        k1 = k2 = 0;
        long long int count = 0;
        for(int j = 0; j < n; j++) {
            if(arr[j] == 0) {
                int two = even[k1];
                int mul4 = four[k2];
                if(two != -1) {
                    if(two != mul4) {
                        count +=  (two - j);
                        int next2 = even[k1 + 1];
                        // std::cout<<j<<" "<<count<<"\n";
                        if(next2 != -1)
                            count += n - next2;
                        // std::cout<<j<<" "<<count<<"\n";
                    }
                    else 
                        count += n - j;
                }
                else 
                    count += (n - j);
            }
            else if(arr[j] == 2) {
                k1++;
                int two = even[k1];
                if(two != -1) {
                    count += n - two;
                }
            }
            else if(arr[j] == 1) {
                k1++;
                k2++;
                count += n - j;
            }
            // std::cout<<j<<" "<<count<<"\n";
        }
        // for(int j = 0; j < n; j++)
        //     std::cout<<even[j];
        // std::cout<<"\n";
        // for(int j = 0; j < n; j++)
        //     std::cout<<four[j];
        // std::cout<<"\n";
        std::cout<<count<<"\n";
    }

    return 0;
}