class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount + 1, 0));

        for(int target = 0; target <= amount; target++) {
            if(target % coins[0] == 0) {
                dp[0][target] = target / coins[0];
            }
            else {
                dp[0][target] = 1e9;
            }
        }

        for(int i=1;i<n;i++) {
            for(int target = 0;target<=amount;target++) {
                int notTake = dp[i-1][target];
                int take = 1e9;

                if(target >= coins[i]) {
                    take = 1 + dp[i][target - coins[i]];
                }

                dp[i][target] = min(take, notTake);
            }
        }

        if(dp[n-1][amount] == 1e9) return -1;
        return dp[n-1][amount];
    }
};