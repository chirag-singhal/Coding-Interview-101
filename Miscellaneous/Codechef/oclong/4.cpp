#include <bits/stdc++.h>
#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        int arr[n], brr[100000] = {0}, crr[100000] = {0}, max = -1;
        vector<int> arr[n];
        for(int j = 0; j < n; j++)
            brr[j] = j;
        for(int j = 0; j < n; j++) {
            int count = 0;
            scanf("%d", &arr[j]);
            for(int k = 0; k < j;) {
                if(arr[k] % arr[j] == 0) {
                    // printf("%d %d\n", arr[j], arr[k]);
                    brr[k] = j;
                    count++;
                }
            }
            if(max < count)
                max = count;
        }
        printf("%d\n", max);
    }
}