#include <iostream>
#include <bits/stdc++.h>

int main() {
    int n, q, k = 0, l = 0, p, r;
    std::cin>>n>>q;
    long int arr[n];
    int brr[n];
    int crr[n];
    bool inc = 0;
    for(int i = 0; i < n; i++) 
        std::cin>>arr[i];
    if(arr[1] > arr[0]) {
        // brr[k++] = 1;
        inc = 1;
    }
    // else 
        // crr[l++] = 1;
    for(int i = 2; i < n; i++) {
        if(inc && arr[i - 1] > arr[i]) {
            crr[l++] = i;
            inc = 0;
        }
        // else if(inc && arr[i - 1] < arr[i] && i == n - 1){
        //     crr[l++] = brr[k];
        //     brr[k++] = i;
        // }
        else if(!inc && arr[i - 1] < arr[i]) {
            brr[k++] = i;
            inc = 1;
        }
    }
    std::vector<int> brrv(brr, brr + k);
    std::vector<int> crrv(crr, crr + l);
    for(int i = 0; i < q; i++) {
        std::cin>>p>>r;
        std::vector<int>::iterator lowb = std::lower_bound(brrv.begin(), brrv.end(), p + 1);
        std::vector<int>::iterator highb = std::upper_bound(brrv.begin(), brrv.end(), r - 1);
        // std::cout<<std::distance(lowb, highb);
        int ans1 = highb - lowb + 1;
        std::vector<int>::iterator lowc = std::lower_bound(crrv.begin(), crrv.end(), p + 1);
        std::vector<int>::iterator highc = std::upper_bound(crrv.begin(), crrv.end(), r - 1);
        // std::cout<<std::distance(lowc, highc);
        int ans2 = highc - lowc + 1;
        if((ans1 + ans2) % 2)
            std::cout<<"YES"<<std::endl;
        else 
            std::cout<<"NO"<<std::endl;
    }
    // for(int i = 0; i < k; i++)
    //     std::cout<<brr[i]<<"    ";
    // std::cout<<std::endl;

    // for(int i = 0; i < l; i++)
    //     std::cout<<crr[i]<<"    ";
    // std::cout<<std::endl;

    return 0;
}