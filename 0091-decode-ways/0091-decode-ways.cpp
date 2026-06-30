class Solution {
public:
    int f(int ind, string& s, vector<int> dp) {
        if(ind == s.size()) return 1;
        if(s[ind] == '0') return 0;
        if(dp[ind] != -1) return dp[ind];

        int oneDigit = f(ind + 1, s, dp);
        int twoDigit = 0;

        if(ind + 1 < s.size()) {
            int num = (s[ind] - '0') * 10 + (s[ind + 1] - '0');

            if(num >= 10 && num <= 26) {
                twoDigit = f(ind + 2, s, dp);
            }
        }

        return dp[ind] = oneDigit + twoDigit;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        dp[n] = 1;

        for(int ind = n - 1; ind >= 0; ind--) {

            if(s[ind] == '0') {
                dp[ind] = 0;
                continue;
            }

            int oneDigit = dp[ind + 1];
            int twoDigit = 0;

            if(ind + 1 < n) {
                int num = (s[ind] - '0') * 10 + (s[ind + 1] - '0');

                if(num >= 10 && num <= 26) {
                    twoDigit = dp[ind + 2];
                }
            }

            dp[ind] = oneDigit + twoDigit;
        }

        return dp[0];
    }
};