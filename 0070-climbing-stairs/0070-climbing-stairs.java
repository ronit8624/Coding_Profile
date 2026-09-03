class Solution {
    public int climbStairs(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);

        dp[0] = 1;
        dp[1] = 1;

        for(int ind = 2; ind <= n; ind++) {
            dp[ind] = dp[ind-1] + dp[ind-2];
        }

        return dp[n];
    }
}