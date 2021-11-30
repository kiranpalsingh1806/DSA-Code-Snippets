#include<bits/stdc++.h>
using namespace std;

int maxWater(int arr[], int n) {
    int total = 0;
    for(int i = 1; i < n - 1; i++) {
        int left = arr[i];
        for(int j = 0; j < i; j++) {
            left = max(left, arr[j]);
        }

        int right = arr[i];
        for(int j = i + 1; j < n; j++) {
            right = max(right, arr[j]);
        }
        total += min(left, right) - arr[i];
    }
    return total;
}

int maxWater2(int arr[], int n) {
    int left[n];
    int right[n];

    int water = 0;

    left[0] = arr[0];
    right[n - 1] = arr[n - 1];

    for(int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], arr[i]);
    }

    for(int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], arr[i]);
    }

    for(int i = 0; i < n; i++) {
        water += min(left[i], right[i]) - arr[i];
    }

    return water;
}

int main() {
    int arr[] = {3, 0, 3, 4, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxWater(arr, n) << "\n";
    cout << maxWater2(arr, n) << "\n";
}