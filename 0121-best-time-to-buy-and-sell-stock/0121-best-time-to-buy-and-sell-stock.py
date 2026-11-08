class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        n = len(prices)
        if n == 1:
            return 0
        
        maxi = float('-inf')
        buy = prices[0]
        profit = 0

        for i in range(1, n):
            if prices[i] < buy:
                buy = prices[i]
            if prices[i] > buy:
                profit = prices[i] - buy
            
            maxi = max(maxi, profit)
        
        return maxi