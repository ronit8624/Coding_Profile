class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1) return 0;
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        dp[1][1] = 1;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(i == 1 && j == 1) continue;
                
                if(obstacleGrid[i-1][j-1] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                
                int top = dp[i-1][j];
                int left = dp[i][j-1];
                
                dp[i][j] = top + left;
            }
        }
        
        return dp[n][m];
    }
};