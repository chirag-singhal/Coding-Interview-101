#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
// int count(int arr[], int no[], int n, int k, int uniq, int karr[], int start) {
//     if(n + start > uniq)
//         return 0;
//     if(n == 0) {
//         long long int ans = 1;
//         for(int i = 0; i < k; i++)
//             ans *= no[karr[i]] % MOD;
//         printf("%lld\n", ans);
//         return ans;
//     }
//     long long int ans = 0;
//     for(int j = start; j < uniq; j++){
//         karr[n - 1] = arr[j];
//         ans += count(arr, no, n - 1, k, uniq, karr, j + 1) % MOD;
//     }
//     printf("%lld\n", ans);
//     return ans;
// }

void vietaFormula(int roots[], int n, long long int coeff[]) 
{ 
    // Declare an array for 
    // polynomial coefficient. 
    // Set all coefficients as zero initially 
    // Set highest order coefficient as 1 
    coeff[n] = 1; 
  
    for (int i = 1; i <= n; i++) { 
        for (int j = n - i - 1; j < n; j++) { 
            coeff[j] = (coeff[j] + (-1) *  
                roots[i - 1] * coeff[j + 1]) % MOD; 
        } 
    } 
} 

int main() {
    int n, k;
    long long int ans = 0;
    scanf("%d", &n);
    scanf("%d", &k);
    int a[8001] = {0}, l = 0, uni = 0, arr[8001] = {0};
    for(int i = 0; i < n; i++){
        scanf("%d", &l);
        if(arr[l] == 0){
            a[uni++] = l;
        }
        arr[l]++;
    }
    int unico[uni];
    long long int coeff[8001] = {0};
    for(int i = 0; i < uni; i++) {
        unico[i] = arr[a[i]];
    }
    vietaFormula(unico, uni, coeff);
    // for(int i = 0; i < uni; i++){
    //     printf("%d\n", a[i]);
    // }
    // for(int i = 0; i <= uni; i++) {
    //     printf("%d %d\n", i, coeff[i]);
    // }
    for(int i = 0; i <= k && i <= uni; i++){
        if(i % 2 != 0)
        {
            ans = ( ans - coeff[uni - i]) % MOD;
            // printf("%d %d %lld %s\n", i, -coeff[uni - i], ans, "odd");
        }
        else {
            ans = (ans + coeff[uni - i]) % MOD;
            // printf("%d %d %lld\n",i, coeff[uni - i], ans);
        }
    }
    printf("%lld\n", ans);
    return 0;
}