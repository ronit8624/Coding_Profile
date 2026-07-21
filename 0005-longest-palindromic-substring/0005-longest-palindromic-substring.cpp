class Solution {
public:
    bool isPalindrome(string& s, int i, int j, vector<vector<int>>& dp) {
        if(i >= j) return true;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) {
            return dp[i][j] = isPalindrome(s, i+1, j-1, dp);
        }

        return dp[i][j] = false;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));

        for(int i=0;i<n;i++) dp[i][i] = true;
        for(int i=1;i<n;i++) dp[i][i-1] = true;
        
        int maxLen = 1;
        int start = 0;

        for(int i=n-2;i>=0;i--) {
            for(int j=i+1;j<n;j++) {
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = false;

                if(dp[i][j] && j-i+1 > maxLen) {
                    maxLen = j-i+1;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

