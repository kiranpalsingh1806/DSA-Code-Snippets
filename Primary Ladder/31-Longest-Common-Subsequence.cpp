#include<bits/stdc++.h>
using namespace std;

int lcs(string &x, string &y) {
    int m = x.length();
    int n = y.length();

    int DP[m + 1][n + 1];

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) {
                DP[i][j] = 0;
            } else if(x[i - 1] == y[j - 1]) {
                DP[i][j] = DP[i- 1][j - 1] + 1;
            } else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    return DP[m][n];
}

void lcsPrint(string &x, string &y) {
    int m = x.length();
    int n = y.length();

    int DP[m + 1][n + 1];

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) {
                DP[i][j] = 0;
            } else if(x[i - 1] == y[j - 1]) {
                DP[i][j] = DP[i- 1][j - 1] + 1;
            } else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    int index = DP[m][n];
    string LCS;

    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(x[i - 1] == y[j - 1]) {
            LCS += x[i - 1];
            i--;
            j--;
        } else if(DP[i - 1][j] > DP[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(LCS.begin(), LCS.end());
    cout << "LCS of " << x << " and " << y << " is " << LCS;

}

int main() {
    string x = "watchkeep";
    string y = "kweaetpch";

    cout << "The length of LCS is : " << lcs(x, y) << "\n";
    lcsPrint(x, y);
}

