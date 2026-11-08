class Solution:
    def f(self, ind, canBuy, n, prices, dp):
        if ind == n:
            return 0
        
        if dp[ind][canBuy] != -1:
            return dp[ind][canBuy]

        profit = 0

        if canBuy:
            not_take = 0 + self.f(ind + 1, canBuy, n, prices, dp)
            take = -prices[ind] + self.f(ind + 1, not canBuy, n, prices, dp)
            profit = max(profit, max(not_take, take))

        else:
            not_take = 0 + self.f(ind + 1, canBuy, n, prices, dp)
            take = prices[ind] + self.f(ind + 1, not canBuy, n, prices, dp)
            profit = max(profit, max(not_take, take))

        dp[ind][canBuy] = profit
        return dp[ind][canBuy]

    def maxProfit(self, prices: list[int]) -> int:
        n = len(prices)
        dp = [[0 for _ in range(2)] for _ in range(n + 1)]

        for ind in range(n-1, -1, -1):
            for canBuy in range(2):
                profit = 0

                if canBuy:
                    not_take = 0 + dp[ind + 1][1]
                    take = -prices[ind] + dp[ind + 1][0]
                    profit = max(profit, max(not_take, take))

                else:
                    not_take = 0 + dp[ind + 1][0]
                    take = prices[ind] + dp[ind + 1][1]
                    profit = max(profit, max(not_take, take))
                
                dp[ind][canBuy] = profit

        return dp[0][1]