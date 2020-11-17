#include <iostream>
#include <bits/stdc++.h>

int main() {
    int t;
    long int tot = 0;
    std::cin>>t;
    for(int i = 0; i < t; i++) {
        int n;
        std::cin>>n;
        int arr[4][4], brr[4][4];
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
                arr[j][k] = 0;
        
        // for(int j = 0; j < 4; j++)
        //     for(int k = 0; k < 4; k++)
        //         brr[j][k] = 0;
        
        char show;
        int tim;
        for(int j = 0; j < n; j++) {
            std::cin>>show>>tim;
            arr[show - 'A'][tim / 3 - 1]++;
            // brr[show - 'A'][tim / 3 - 1]++;
        }

        // for(int j = 0; j < 4; j++) {
        //     int min = brr[j][0];
        //     for(int k = 0; k < 4; k++)
        //         if(brr[j][k] < min)
        //             min = brr[j][k];
        //     for(int k = 0; k < 4; k++)
        //         brr[j][k] -= min;
        // }

        // for(int j = 0; j < 4; j++) {
        //     int min = brr[0][j];
        //     for(int k = 0; k < 4; k++)
        //         if(brr[k][j] < min)
        //             min = brr[k][j];
        //     for(int k = 0; k < 4; k++)
        //         brr[k][j] -= min;
        // }
        // int crr[4];
        // for(int j = 0; j < 4; j++) {
        //     int k = 0;
        //     crr[k++] = arr[0][j]; 
        //     for(int l = 0; l < 4; l++) {
        //         if(l == j)
        //             continue;
        //         crr[k] = arr[k][l];
        //         k++;
        //     }
        // }

        int crr[96] = { arr[0][0], arr[1][1], arr[2][2], arr[3][3],
                        arr[0][0], arr[1][2], arr[2][1], arr[3][3],
                        arr[0][0], arr[1][3], arr[2][2], arr[3][1],
                        arr[0][0], arr[1][1], arr[2][3], arr[3][2],
                        arr[0][0], arr[1][2], arr[2][3], arr[3][1],
                        arr[0][0], arr[1][3], arr[2][1], arr[3][2],
                        arr[0][1], arr[1][0], arr[2][2], arr[3][3],
                        arr[0][1], arr[1][2], arr[2][0], arr[3][3],
                        arr[0][1], arr[1][3], arr[2][2], arr[3][0],
                        arr[0][1], arr[1][0], arr[2][3], arr[3][2],
                        arr[0][1], arr[1][2], arr[2][3], arr[3][0],
                        arr[0][1], arr[1][3], arr[2][0], arr[3][2],
                        arr[0][2], arr[1][0], arr[2][1], arr[3][3],
                        arr[0][2], arr[1][1], arr[2][0], arr[3][3],
                        arr[0][2], arr[1][3], arr[2][1], arr[3][0],
                        arr[0][2], arr[1][0], arr[2][3], arr[3][1],
                        arr[0][2], arr[1][1], arr[2][3], arr[3][0],
                        arr[0][2], arr[1][3], arr[2][0], arr[3][1],
                        arr[0][3], arr[1][0], arr[2][2], arr[3][1],
                        arr[0][3], arr[1][2], arr[2][0], arr[3][1],
                        arr[0][3], arr[1][1], arr[2][2], arr[3][0],
                        arr[0][3], arr[1][0], arr[2][1], arr[3][2],
                        arr[0][3], arr[1][2], arr[2][1], arr[3][0],
                        arr[0][3], arr[1][1], arr[2][0], arr[3][2]
                    };
        int drr[4], max = -400;
        for(int i = 0; i < 24; i++) {
            int sum = 0;
            for(int k = 0; k < 4; k++) {
                drr[k] = crr[i * 4 + k];
            }
            std::sort(drr, drr + 4);
            for(int k = 0; k < 4; k++) {
                if(drr[k] == 0)
                    sum -= 100;
                else 
                    sum += 25 * (k + 1) * drr[k];
            }
            if(max < sum)
                max = sum;
            // std::cout<<max<<" ";
        }
        tot += max;
        std::cout<<max<<std::endl;
    }
    std::cout<<tot<<std::endl;
    return 0;
}