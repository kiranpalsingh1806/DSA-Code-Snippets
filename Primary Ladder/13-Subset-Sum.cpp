#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int n, int sum) {
    if(sum == 0) {
        return true;
    } 
    if(n == 0) {
        return false;
    }
    if(arr[n - 1] > sum) {
        return subsetSum(arr, n - 1, sum);
    }

    return subsetSum(arr, n - 1, sum) || subsetSum(arr, n - 1, sum - arr[n - 1]);
}

bool subsetSumDP(int arr[], int n, int sum) {
    bool DP[n + 1][sum + 1];

    for(int i = 0; i <= n; i++) {
        DP[i][0] = true;
    }

    for(int i = 1; i <= sum; i++) {
        DP[0][i] = false;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(j < arr[i - 1]) {
                DP[i][j]  = DP[i - 1][j];
            } else {
                DP[i][j] = DP[i - 1][j] || DP[i - 1][j - arr[i - 1]];
            }
        }
    }
    return DP[n][sum];
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    int n = sizeof(arr) / sizeof(arr[0]);

    if(subsetSum(arr, n, sum)) {
        cout << "Found Subset with given sum" << "\n";
    } else {
        cout << "No subset with given sum" << "\n";
    }

    if(subsetSumDP(arr, n, sum)) {
        cout << "Found Subset with given sum" << "\n";
    } else {
        cout << "No subset with given sum" << "\n";
    }
}