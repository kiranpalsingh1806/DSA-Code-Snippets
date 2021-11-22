#include<bits/stdc++.h>
using namespace std;

int coinChangeDP(vector<int>& a, int v, int n, vector<vector<int>>& dp) {
    if (v == 0)
        return dp[n][v] = 1;
    if (n == 0)
        return 0;
    if (dp[n][v] != -1)
        return dp[n][v];
    if (a[n - 1] <= v) {
        return dp[n][v] = coinChangeDP(a, v - a[n - 1], n, dp) + coinChangeDP(a, v, n - 1, dp);
    } else {
    	return dp[n][v] = coinChangeDP(a, v, n - 1, dp);
    }     
}

int main() {
    vector<int> a = { 1, 2, 3 };
    int n = 3;
    int v = 4;
    vector<vector<int> > dp(n + 1,vector<int>(v + 1, -1));
    int res = coinChangeDP(a, v, n, dp);

    cout << res << "\n";
    return 0;
}