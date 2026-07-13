class Solution {
public:
    int f(int ind, int target, vector<int>& arr, 
              vector<vector<int>>& dp) {
            if(ind == 0) {
                if(target % arr[ind] == 0)
                    return target / arr[ind];
                else 
                    return -1;
            }

            if(dp[ind][target] != -1) 
                return dp[ind][target];

            int notTake = 0 + f(ind - 1, target, arr, dp);
            int take = 1e9;

            if(target >= arr[ind]) {
                take = 1 + f(ind, target - arr[ind], arr, dp);
            }

            return dp[ind][target] = min(notTake, take);
        }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
            
            for(int target = 0; target <= amount; target ++) {
                if(target % coins[0] == 0)
                    dp[0][target] = target / coins[0];
                else 
                    dp[0][target] = 1e9;
            }

            for(int ind = 1; ind < n; ind ++) {
                for(int target = 0; target <= amount; target ++) {
                    int notTake = 0 + dp[ind - 1][target];
                    int take = 1e9;

                    if(target >= coins[ind]) {
                        take = 1 + dp[ind][target - coins[ind]];
                    }

                    dp[ind][target] = min(notTake, take);
                }
            }

            if(dp[n - 1][amount] >= 1e9) {
                return -1;
            }

            return dp[n - 1][amount];
    }
};