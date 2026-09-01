class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int maxi = 0;
        int buy = prices[0], profit = 0;

        for(int i=1;i<n;i++) {
            if(prices[i] < buy) buy = prices[i];
            if(prices[i] > buy) profit = prices[i] - buy;
            maxi = Math.max(maxi, profit);
        }

        return maxi;
    }
}