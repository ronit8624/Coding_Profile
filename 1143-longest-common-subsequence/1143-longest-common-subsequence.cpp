class Solution {
public:
    int f(int ind1, int ind2, string& s, string& t, vector<vector<int>>& dp) {
        if(ind1 == 0 || ind2 == 0)
            return 0;

        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        int notMatch1 = f(ind1 - 1, ind2, s, t, dp);
        int notMatch2 = f(ind1, ind2 - 1, s, t, dp);

        int match = 0;
        if(s[ind1 - 1] == t[ind2 - 1]) {
            match = 1 + f(ind1 - 1, ind2 - 1, s, t, dp);
        }

        return dp[ind1][ind2] = max(match, max(notMatch1, notMatch2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        // return f(n1, n2, text1, text2, dp);
        for(int ind2 = 0; ind2 <= n2; ind2++) {
            dp[0][ind2] = 0;
        }

        for(int ind1 = 0; ind1 <= n1; ind1++) {
            dp[ind1][0] = 0;
        }

        for(int ind1 = 1; ind1 <= n1; ind1++) {
            for(int ind2 = 1; ind2 <= n2; ind2++) {
                int notMatch1 = dp[ind1-1][ind2];
                int notMatch2 = dp[ind1][ind2-1];

                int match = 0;
                if(text1[ind1 - 1] == text2[ind2 - 1]) {
                    match = 1 + dp[ind1-1][ind2-1];
                }

                dp[ind1][ind2] = max(match, max(notMatch1, notMatch2));
            }
        }

        return dp[n1][n2];
    }
};