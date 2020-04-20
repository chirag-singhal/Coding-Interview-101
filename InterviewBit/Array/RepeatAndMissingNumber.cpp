#include <bits/stdc++.h>

std::vector<int> repeatedNumber(const std::vector<int> &A) {
    long int n = A.size();
    long long int sum = (long) n * (n + 1);
    long long int squareSum = n * (n + 1) * (2 * n + 1);
    squareSum /= 6;
    sum /= 2;
    std::vector<int> ans;
    for(int i = 0; i < n; i++) {
        squareSum -= (long long int) A[i] * (long long int) A[i];
        sum -= (long long int) A[i];
    }
    long long int eq1 = squareSum / sum;
    ans.push_back((eq1 - sum) / 2);
    ans.push_back((eq1 + sum) / 2);
    return ans;
}
