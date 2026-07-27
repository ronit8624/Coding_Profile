class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0, maxi = 0;
        unordered_map<int, int> freq;
        int l = 0;

        for (int r = 0; r < n; r++) {
            sum += nums[r];
            freq[nums[r]]++;

            while (freq[nums[r]] > 1) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0)
                    freq.erase(nums[l]);
                sum -= nums[l];
                l++;
            }

            while (r - l + 1 > k) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0)
                    freq.erase(nums[l]);
                sum -= nums[l];
                l++;
            }

            if (r - l + 1 == k)
                maxi = max(maxi, sum);
        }

        return maxi;
    }
};