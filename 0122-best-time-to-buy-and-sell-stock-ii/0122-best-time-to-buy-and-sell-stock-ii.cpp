class Solution {
public:
    int f(int ind, int canBuy, vector<int>& prices, int n, 
          vector<vector<int>>& dp) {

        if(ind == n) return 0;
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];

        int profit = 0;

        if(canBuy) {
            int notTake = 0 + f(ind+1, 1, prices, n, dp);
            int take = -prices[ind] + f(ind+1, 0, prices, n, dp);

            profit = max(profit, max(take, notTake));
        }
        else {
            int notTake = 0 + f(ind+1, 0, prices, n, dp);
            int take = prices[ind] + f(ind+1, 1, prices, n, dp);

            profit = max(profit, max(take, notTake));
        }

        return dp[ind][canBuy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;

        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        vector<int> prev(2, 0), curr(2, 0);
        prev[0] = prev[1] = 0;

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int canBuy = 0; canBuy < 2; canBuy++) {

                int profit = 0;

                if(canBuy) {
                    // int notTake = dp[ind + 1][1];
                    int notTake = prev[1];
                    // int take = -prices[ind] + dp[ind + 1][0];
                    int take = -prices[ind] + prev[0];

                    profit = max(take, notTake);
                }
                else {
                    // int notTake = dp[ind + 1][0];
                    int notTake = prev[0];
                    // int take = prices[ind] + dp[ind + 1][1];
                    int take = prices[ind] + prev[1];

                    profit = max(take, notTake);
                }

                curr[canBuy] = profit;
            }

            prev = curr;
        }

        return curr[1];
    }
};