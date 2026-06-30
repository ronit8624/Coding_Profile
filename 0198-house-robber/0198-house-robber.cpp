class Solution {
public:
    int f(int ind, vector<int>& nums, vector<int>& dp) {
        if(ind < 0) return 0;
        if(ind == 0) return nums[0];
        if(dp[ind] != -1) return dp[ind];

        int not_take = f(ind - 1, nums, dp);
        int take = nums[ind] + f(ind - 2, nums, dp);

        return dp[ind] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev2 = 0;
        int prev1 = nums[0];

        for(int i = 1; i < n; i++) {
            int take = nums[i] + prev2;
            int notTake = prev1;

            int cur = max(take, notTake);

            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};