class Solution {
public:
    int f(int i, int j, int n, vector<vector<int>>& mat, 
            vector<vector<int>>& dp) {

        if(j < 0 || j >= n) return 1e9;
        if(i == 0) return mat[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int top = mat[i][j] + f(i-1, j, n, mat, dp);
        int left = mat[i][j] + f(i-1, j-1, n, mat, dp);
        int right = mat[i][j] + f(i-1, j+1, n, mat, dp);

        return dp[i][j] = min(top, min(left, right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0) {
                    dp[0][j] = matrix[0][j];
                    continue;
                }

                int top = matrix[i][j] + dp[i-1][j];

                int left = INT_MAX;
                if(j > 0)
                    left = matrix[i][j] + dp[i-1][j-1];

                int right = INT_MAX;
                if(j < n-1)
                    right = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min(top, min(left, right));
            }
        }

        int ans = INT_MAX;

        for(int j = 0; j < n; j++)
            ans = min(ans, dp[m-1][j]);

        return ans;
    }
};