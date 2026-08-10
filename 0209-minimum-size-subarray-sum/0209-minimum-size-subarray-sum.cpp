class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int j = 0;
        int mini = INT_MAX;

        for(int i=0;i<n;i++) {
            sum += nums[i];

            while(sum >= target) {
                mini = min(mini, i - j + 1);
                sum -= nums[j];
                j++;
            }
        }

        return mini == INT_MAX ? 0 : mini;
    }
};