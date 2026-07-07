class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int n, int fee, 
          vector<vector<int>>& dp) {
        if(ind == n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];
        int maxi = 0;

        if(buy) {
            int notTake = 0 + f(ind + 1, 1, prices, n, fee, dp);
            int take = -prices[ind] + f(ind + 1, 0, prices, n, fee, dp);

            maxi = max(maxi, max(notTake, take));
        }
        else {
            int notTake = 0 + f(ind + 1, 0, prices, n, fee, dp);
            int take = prices[ind] - fee + f(ind + 1, 1, prices, n, fee, dp);

            maxi = max(maxi, max(notTake, take));
        }

        return dp[ind][buy] = maxi;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n == 0) return 0;

        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        vector<int> prev(2, 0), curr(2, 0);

        for(int ind = n-1; ind >= 0; ind--) {
            for(int buy = 0; buy < 2; buy++) {

                int maxi = 0;

                if(buy) {
                    int notTake = 0 + prev[1];
                    int take = -prices[ind] + prev[0];

                    maxi = max(maxi, max(notTake, take));
                }
                else {
                    int notTake = 0 + prev[0];
                    int take = prices[ind] - fee + prev[1];

                    maxi = max(maxi, max(notTake, take));
                }

                curr[buy] = maxi;
            }

            prev = curr;
        }

        return curr[1];
    }
};