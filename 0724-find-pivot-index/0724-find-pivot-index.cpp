class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i=0;i<n;i++) {
            sum += nums[i];
        }

        int lsum = 0;

        for(int i=0;i<n;i++) {
            int rsum = sum - lsum - nums[i];

            if(lsum == rsum) {
                return i;
            }

            lsum += nums[i];
        }

        return -1;
    }
};