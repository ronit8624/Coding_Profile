class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // return f(n, m, word1, word2, dp);
        for(int j=0;j<=m;j++) {
            dp[0][j] = j;
        }

        for(int i=0;i<=n;i++) {
            dp[i][0] = i;
        }

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                int insertion = 0, deletion = 0, replace = 0;

                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    insertion = 1 + dp[i][j-1];
                    deletion = 1 + dp[i-1][j];
                    replace = 1 + dp[i-1][j-1];

                    dp[i][j] = min({insertion, deletion, replace});
                }
            }
        }

        return dp[n][m];
    }
};