class Solution {
public:
    int f(int row, int col, vector<vector<int>>& dp) {
        if(row == 1 && col == 1) return 1;
        if(row == 0 || col == 0) return 0;
        if(dp[row][col] != -1) return dp[row][col];

        int top = f(row - 1, col, dp);
        int left = f(row, col - 1, dp);

        return dp[row][col] = top + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        dp[1][1] = 1;

        for(int row = 1; row <= m; row++) {
            for(int col = 1; col <= n; col++) {
                if(row == 1 && col == 1) continue;
                
                int top = dp[row-1][col];
                int left = dp[row][col-1];

                dp[row][col] = top + left;
            }
        }

        return dp[m][n];
    }
};