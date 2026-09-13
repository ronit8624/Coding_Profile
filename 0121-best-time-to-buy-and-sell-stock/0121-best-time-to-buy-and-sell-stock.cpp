class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = INT_MIN;
        int buy = prices[0], profit = 0;

        for(int i=0;i<n;i++) {
            if(prices[i] < buy) buy = prices[i];
            if(prices[i] > buy) profit = prices[i] - buy;
            maxi = max(maxi, profit);
        }

        return maxi;
    }
};