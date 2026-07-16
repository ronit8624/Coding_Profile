class Solution {
public:
    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int notMatch1 = f(i-1, j, s, t, dp);
        int notMatch2 = f(i, j-1, s, t, dp);
        int match = 0;

        if(s[i-1] == t[j-1]) {
            match = 1 + f(i-1, j-1, s, t, dp);
        }

        return dp[i][j] = max(match, max(notMatch1, notMatch2));
    }
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
};