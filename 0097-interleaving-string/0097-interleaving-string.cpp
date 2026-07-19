class Solution {
public:
    bool f(int i, int j, string& s1, string& s2, string& s3, 
           vector<vector<bool>>& dp) {
        if(i == s1.size() && j == s2.size()) {
            return true;
        }

        if(i == s1.size()) {
            while(j < s2.size()) {
                if(s3[i+j] != s2[j]) return false;
                j++;
            }
            return true;
        }

        if(j == s2.size()) {
            while(i < s1.size()) {
                if(s3[i+j] != s1[i]) return false;
                i++;
            }
            return true;
        }

        if(dp[i][j] != false) return dp[i][j];

        bool takes1 = false, takes2 = false;

        if(s3[i+j] == s1[i]) {
            takes1 = f(i+1, j, s1, s2, s3, dp);
        }

        if(s3[i+j] == s2[j]) {
            takes2 = f(i, j+1, s1, s2, s3, dp);
        }

        return dp[i][j] = takes1 || takes2;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();

        if(m + n != s3.size()) return false;

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;

        for(int j = n - 1; j >= 0; j--) {
            if(s2[j] == s3[m + j]) {
                dp[m][j] = dp[m][j + 1];
            }
            else {
                dp[m][j] = false;
            }
        }

        for(int i = m - 1; i >= 0; i--) {
            if(s1[i] == s3[i + n]) {
                dp[i][n] = dp[i + 1][n];
            }
            else {
                dp[i][n] = false;
            }
        }

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {

                bool takeS1 = false;
                bool takeS2 = false;

                if(s1[i] == s3[i + j])
                    takeS1 = dp[i + 1][j];

                if(s2[j] == s3[i + j])
                    takeS2 = dp[i][j + 1];

                dp[i][j] = takeS1 || takeS2;
            }
        }

        return dp[0][0];
    }
};