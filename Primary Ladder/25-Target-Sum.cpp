#include<bits/stdc++.h>
using namespace std;

int countSubsets(vector<int>& nums, int n, int M) {
    int t[n + 1][M + 1];
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= M; j++) {
            if(i == 0) {
                t[i][j] = 0;
            } 
            if(j == 0) {
                t[i][j] = 1;
            }   
        }
    }  
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= M; j++) {
            if(nums[i - 1] <= j) {
                t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }  
    return t[n][M];  
}



int findTargetSumWays(vector<int>& nums, int target) {
    target = abs(target);
    int n = nums.size();
    int sum = 0;

    for(int i = 0; i < n; i++) {
       sum += nums[i]; 
    }

    int M = (sum + target)/2;
    if(sum < target || (sum + target) % 2 != 0) {
        return 0;
    }
    return countSubsets(nums, n, M);
}

int main() {
    int S = 3;
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    cout << "The number of ways of getting target sum is " <<  findTargetSumWays(nums, S) << "\n";
}

