class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        long long prod = 1LL;
        int positives = 0;
        int negatives = 0;
        int zeros = 0;

        int maxNeg = INT_MIN;

        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                positives++;
                prod *= nums[i];
            }
            else if(nums[i] < 0) {
                negatives++;
                prod *= nums[i];
                maxNeg = max(maxNeg, nums[i]);
            }
            else {
                zeros++;
            }
        }

        if(positives == 0 && negatives == 0)
            return 0;

        if(negatives % 2 != 0) {
            prod /= maxNeg;

            if(negatives == 1 && positives == 0)
                return (zeros > 0) ? 0 : maxNeg;
        }

        return prod;
    }
};