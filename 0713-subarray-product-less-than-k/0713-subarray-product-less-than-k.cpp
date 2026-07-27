class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        int n = nums.size();
        int cnt = 0, prod = 1;
        int l = 0;

        for(int i=0;i<n;i++) {
            prod *= nums[i];

            while(prod >= k) {
                prod /= nums[l];
                l++;
            }

            cnt += (i - l + 1);
        }

        return cnt;
    }
};