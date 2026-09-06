class Solution {
    private int f(int ind, int[] points, int[] dp) {
        if(ind == 0) return 0;
        if(ind == 1) return points[1];

        if(dp[ind] != -1) return dp[ind];

        int take = points[ind] + f(ind - 2, points, dp);
        int notTake = f(ind - 1, points, dp);

        return dp[ind] = Math.max(take, notTake);
    }

    public int deleteAndEarn(int[] nums) {
        int n = nums.length;
        int maxi = Integer.MIN_VALUE;

        for(int i=0;i<n;i++) {
            maxi = Math.max(maxi, nums[i]);
        }

        int[] points = new int[maxi + 1];
        for(int i=0;i<n;i++) {
            points[nums[i]] += nums[i];
        }

        int[] dp = new int[maxi + 1];
        Arrays.fill(dp, 0);

        dp[0] = 0;
        dp[1] = points[1];

        for(int ind = 2; ind <= maxi; ind++) {
            int take = points[ind] + dp[ind - 2];
            int notTake = dp[ind - 1];

            dp[ind] = Math.max(take, notTake);
        }

        return dp[maxi];
    }
}