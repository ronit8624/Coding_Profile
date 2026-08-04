class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        } 

        return true;
    }
    int f(int ind, int n, string& s, vector<int>& dp) {
        if(ind == n) return 0;
        if(dp[ind] != -1) return dp[ind];

        int mini = 1e9;

        for(int i=ind;i<n;i++) {
            if(isPalindrome(s, ind, i)) {
                int cost = 1 + f(i + 1, n, s, dp);
                mini = min(mini, cost);
            }
        }

        return dp[ind] = mini;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for(int ind = n-1; ind >= 0; ind--) {
            int mini = 1e9;

            for(int i=ind;i<n;i++) {
                if(isPalindrome(s, ind, i)) {
                    int cost = 1 + dp[i + 1];
                    mini = min(mini, cost);
                }
            }

            dp[ind] = mini;
        }

        return dp[0] - 1;
    }
};