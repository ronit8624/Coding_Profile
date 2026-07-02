class Solution {
public:
    int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if(i==0 && j==0) return 1;
        if(i < 0 || j < 0) return 0;
        if(mat[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int top = f(i-1, j, mat, dp);
        int left = f(i, j-1, mat, dp);

        return dp[i][j] = top + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i=0;i<m;i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) {
                    dp[i][j] = 1;
                    continue;
                }
                else {
                    if(obstacleGrid[i][j] == 1) {
                        dp[i][j] = 0;
                        continue;
                    }

                    int top = 0;
                    int left = 0;
                    if(i > 0) top = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];

                    dp[i][j] = top + left;
                }
            }
        }

        return dp[m-1][n-1];
    }
};