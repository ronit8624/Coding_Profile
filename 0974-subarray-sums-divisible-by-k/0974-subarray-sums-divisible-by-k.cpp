class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int preSum = 0;
        int cnt = 0;

        for(int i=0;i<n;i++) {
            preSum += nums[i];
            int reqSum = preSum % k;

            if(reqSum < 0) reqSum += k;
            if(mpp.find(reqSum) != mpp.end()) {
                cnt += mpp[reqSum];
            }

            mpp[reqSum]++;
        }

        return cnt;
    }
};