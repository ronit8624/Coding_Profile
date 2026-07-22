class Solution {
public:
    int f(int n, vector<int>& dp) {
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];

        int ans = INT_MIN;

        for(int i=1;i<n;i++) {
            int prod = i * max(n-i, f(n-i, dp));
            ans = max(ans, prod);
        }

        return dp[n] = ans;
    }

    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};