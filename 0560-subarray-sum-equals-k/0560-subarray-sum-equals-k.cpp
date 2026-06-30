class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp; // <prefixSum, cnt>
        int cnt = 0, prefixSum = 0;
        mpp[0] = 1;

        for(int i=0;i<n;i++) {
            prefixSum += nums[i];
            int requiredSum = prefixSum - k;

            if(mpp.find(requiredSum) != mpp.end()) {
                cnt += mpp[requiredSum];
            }

            mpp[prefixSum]++;
        }

        return cnt;
    }
};