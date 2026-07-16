class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        // int ans = f(n, n, s, t, dp);
        // return ans;

        for(int j=0;j<=n;j++) dp[0][j] = 0;
        for(int i=0;i<=n;i++) dp[i][0] = 0;

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                int notMatch1 = dp[i-1][j];
                int notMatch2 = dp[i][j-1];
                int match = 0;

                if(s[i-1] == t[j-1]) {
                    match = 1 + dp[i-1][j-1];
                }

                dp[i][j] = max(match, max(notMatch1, notMatch2));
            }
        }

        return dp[n][n];
    }

    int minInsertions(string s) {
        int longestPalindromeLength = longestPalindromeSubseq(s);
        return s.size() - longestPalindromeLength;
    }
};