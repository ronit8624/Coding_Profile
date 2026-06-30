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
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};