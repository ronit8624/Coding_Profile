class Solution {
public:
    int f(int ind, int canBuy, vector<int>& prices, int n,
          vector<vector<int>>& dp) {

        if(ind >= n) return 0;
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];

        int profit = 0;

        if(canBuy) {
            int notTake = f(ind + 1, 1, prices, n, dp);
            int take = -prices[ind] + f(ind + 1, 0, prices, n, dp);

            profit = max(take, notTake);
        }
        else {
            int notTake = f(ind + 1, 0, prices, n, dp);
            int take = prices[ind] + f(ind + 2, 1, prices, n, dp);

            profit = max(take, notTake);
        }

        return dp[ind][canBuy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;

        vector<int> front1(2, 0), front2(2, 0), curr(2, 0);

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int buy = 0; buy < 2; buy++) {

                int profit = 0;

                if(buy) {
                    int notTake = front1[1];
                    int take = -prices[ind] + front1[0];

                    profit = max(take, notTake);
                }
                else {
                    int notTake = front1[0];
                    int take = prices[ind] + front2[1];

                    profit = max(take, notTake);
                }

                curr[buy] = profit;
            }

            front2 = front1;
            front1 = curr;
        }

        return front1[1];
    }
};