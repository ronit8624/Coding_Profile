class Solution {
public:
    int f(int ind, int prev, int n, vector<int>& nums, 
          vector<vector<int>>& dp) {
        if(ind == n) return 0;
        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int notTake = f(ind + 1, prev, n, nums, dp);
        int take = 0;

        if(prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + f(ind + 1, ind, n, nums, dp);
        }

        return dp[ind][prev + 1] = max(notTake, take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // // return f(0, -1, n, nums, dp);

        // for(int prev = 0; prev <= n; prev++) {
        //     dp[n][prev] = 0;
        // }

        // for(int ind = n-1; ind >= 0; ind--) {
        //     for(int prev = i-1; prev >= -1; prev--) {
        //         int notTake = dp[ind + 1][prev];
        //         int take = 0;

        //         if(prev == -1 || nums[ind] > nums[prev]) {
        //             take = 1 + dp[ind + 1][ind];
        //         }

        //         dp[ind][prev + 1] = max(notTake, take);
        //     }
        // }

        // Not more intuitive tabulation
        vector<int> dp(n + 1, 1);
        int maxi = 1;

        for(int ind = 0; ind < n; ind++) {
            for(int prev = 0; prev < ind; prev++) {
                if(nums[ind] > nums[prev]) {
                    dp[ind] = max(dp[ind], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[ind]);
        }

        return maxi;
    }
};