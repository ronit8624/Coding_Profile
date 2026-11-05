class Solution {
private:
    int f(vector<int>& nums, vector<int>& dp) {
        dp[0] = 0;
        dp[1] = nums[0];

        for(int ind = 2; ind <= nums.size(); ind++) {
            int not_take = dp[ind - 1];
            int take = nums[ind - 1] + dp[ind - 2];

            dp[ind] = max(take, not_take);
        }

        return dp[nums.size()];
    }

public:
    int rob(vector<int>& nums) {
        vector<int> nums1, nums2;

        int n = nums.size();

        if(n == 1) return nums[0];

        for(int i = 1; i < n; i++)
            nums1.push_back(nums[i]);

        for(int i = 0; i < n - 1; i++)
            nums2.push_back(nums[i]);

        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);

        return max(f(nums1, dp1),
                   f(nums2, dp2));
    }
};