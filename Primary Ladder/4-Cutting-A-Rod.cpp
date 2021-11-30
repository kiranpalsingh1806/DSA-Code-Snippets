#include<bits/stdc++.h>
using namespace std;

const int N = 9;
int dp[N][N];

int rodCutting(int price[], int length[], int maxLen, int n) {
    if(n == 0 || maxLen == 0) {
        return 0;
    }
    if(length[n - 1] <= maxLen) {
        dp[n][maxLen] = max(price[n - 1] + rodCutting(price, length, maxLen - length[n - 1], n),
        rodCutting(price, length, maxLen, n - 1));
    } else {
        dp[n][maxLen] = rodCutting(price, length, maxLen, n - 1);
    }

    return dp[n][maxLen];
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]);

    int length[n];

    for(int i = 0; i < n; i++) {
        length[i] = i + 1;
    }
    int maxLen = n;
    cout << "Maximum obtained value is " << rodCutting(price, length, n, maxLen) << "\n";
}