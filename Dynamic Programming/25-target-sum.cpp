#include<bits/stdc++.h>
using namespace std;

int targetSum(vector<int>& nums, int S) {
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }

    if(S < -sum || S > sum) {
        return 0;
    }

    vector<vector<int>> dp(nums.size() + 1, vector<int>(sum * 2 + 1, 0));

    dp[0][sum] = 1;

    for(int i = 1; i <= nums.size(); i++) {
        for(int j = 0; j < sum * 2 + 1; j++) {
            if(j + nums[i - 1] < sum * 2 + 1) {
                dp[i][j] += dp[i - 1][j + nums[i - 1]];
            }
            if(j - nums[i - 1] >= 0) {
                dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[nums.size()][sum + S];
    }
}

int main() {
    int S = 4;
    vector<int> nums = {1, 2, 3, 4, 1, 1, 1, 1};

    cout << targetSum(nums, S) << "\n";
}
