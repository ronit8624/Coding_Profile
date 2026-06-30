class Solution {
public:
    int f(int ind, vector<int>& dp) {
        if(ind == 0) return 1;
        if(dp[ind] != -1) return dp[ind];

        int step1 = f(ind - 1, dp);
        int step2 = 0;

        if(ind > 1) {
            step2 = f(ind-2, dp);
        }

        return dp[ind] = step1 + step2;
    }

    int climbStairs(int n) {
        // vector<int> dp(n+1, -1);
        // dp[0] = 1;
        // dp[1] = 1;

        int prev1 = 1;
        int prev2 = 1;

        for(int i=2;i<=n;i++) {
            // int step1 = dp[i-1];
            // int step2 = dp[i-2];
            // dp[i] = step1 + step2;

            int cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};