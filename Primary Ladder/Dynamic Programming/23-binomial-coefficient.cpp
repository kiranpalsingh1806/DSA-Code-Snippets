#include<bits/stdc++.h>
using namespace std;

int binomial_coefficient(int n, int k) {
    if(k > n) {
        return 0;
    }
    if(k == 0 || k == n) {
        return 1;
    }
    return binomial_coefficient(n - 1, k - 1) + binomial_coefficient(n - 1, k);
}

int binomial_coefficient_dp(int n, int k) {
    int C[n + 1][k + 1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= min(i, k); j++) {
            if(j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }

    return C[n][k];
}

int main() {
    int n = 5, k = 2;
    cout << "Value of C(" << n << ", " << k << ") is " << binomial_coefficient(n, k) << "\n";
    cout << "Value of C(" << n << ", " << k << ") is " << binomial_coefficient_dp(n, k) << "\n";
    return 0;
}

