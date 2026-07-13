class Solution {
public:
    int f(int ind, int target, vector<int>& coins) {
        if(ind == 0) {
            if(target % coins[0] == 0) return 1;
            else return 0;
        }

        int notTake = f(ind - 1, target, coins);
        int take = 0;

        if(target >= coins[ind]) {
            take = f(ind, target - coins[ind], coins);
        }

        return notTake + take;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));

        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0)
                dp[0][t] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                dp[i][t] = dp[i - 1][t];
                if (t >= coins[i])
                    dp[i][t] += dp[i][t - coins[i]];
            }
        }

        return (int)dp[n - 1][amount];
    }
};