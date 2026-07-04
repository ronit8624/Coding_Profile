class Solution {
public:
    int kadanesMin(vector<int>& nums, int n) {
        int sum = nums[0];
        int mini = nums[0];

        for(int i = 1; i < n; i++) {
            sum = min(sum + nums[i], nums[i]);
            mini = min(mini, sum);
        }

        return abs(mini);
    }

    int kadanesMax(vector<int>& nums, int n) {
        int sum = nums[0];
        int maxi = nums[0];

        for(int i = 1; i < n; i++) {
            sum = max(sum + nums[i], nums[i]);
            maxi = max(maxi, sum);
        }

        return maxi;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int minSum = kadanesMin(nums, n);
        int maxSum = kadanesMax(nums, n);

        return max(minSum, maxSum);
    }
};