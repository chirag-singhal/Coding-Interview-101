#include <bits/stdc++.h>

int main() {
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++) {
        int n, q, count = 0;
        std::cin>>n>>q;
        std::string s;
        std::cin>>s;
        std::vector<int> arr(26, 0);
        std::vector<int> brr(n + 1, 0);
        for(int j = 0; j < n; j++) {
            if(arr[s[j] - 'a'] == 0)
                count++;
            arr[s[j] - 'a']++;
        }
        // for(int j = 0; j < 26; j++)
        //     std::cout<<arr[j]<<" ";
        // std::cout<<"\n";
        // std::cout<<count<<"\n";
        for(int j = 0; j < 26; j++) {
            if(arr[j] != 0)
                brr[arr[j]]++;
        }
        for(int j = 1; j < n; j++) {
            brr[j] = brr[j] + brr[j - 1];
        }
        for(int j = 1; j < n; j++) {
            brr[j] = brr[j] + brr[j - 1];
        }
        for(int j = 0; j < q; j++) {
            long int c;
            std::cin>>c;
            if(c == 0)
                std::cout<<n<<"\n";
            else if(c >= n)
                std::cout<<"0\n";
            else if(n - count * c + brr[c - 1] > 0)
                std::cout<<n - count * c + brr[c - 1]<<"\n";
            else
                std::cout<<"0\n";
        }
    }
    return 0;
}