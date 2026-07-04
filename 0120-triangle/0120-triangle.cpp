class Solution {
public:
    int f(int i, int j, vector<vector<int>>& mat, 
          vector<vector<int>>& dp) {

        if(i == mat.size()-1) {
            return mat[i][j];
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int bottom = mat[i][j] + f(i+1, j, mat, dp);
        int bottom_right = mat[i][j] + f(i+1, j+1, mat, dp);

        return dp[i][j] = min(bottom, bottom_right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int j=0;j<n;j++) {
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--) {
            for(int j=i;j>=0;j--) {

                int bottom = triangle[i][j] + dp[i+1][j];
                int bottom_right = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(bottom, bottom_right);
            }
        }

        return dp[0][0];
    }
};