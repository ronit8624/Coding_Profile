class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0, minLen = INT_MAX, l = 0, r = 0;

        while(r < n) {
            sum += nums[r];

            while(sum >= target) {
                int len = r - l + 1;
                minLen = min(minLen, len);
                sum -= nums[l];
                l++;
            }

            r++;
        }

        if(minLen == INT_MAX) return 0;
        return minLen;
    }
};