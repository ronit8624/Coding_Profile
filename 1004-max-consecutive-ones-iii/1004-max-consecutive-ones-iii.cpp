class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeros = 0, maxi = 0, l = 0;
        
        for(int r=0;r<n;r++) {
            if(nums[r] == 0) zeros++;

            if(zeros > k) {
                if(nums[l] == 0) {
                    zeros--;
                }
                l++;
            }

            maxi = max(maxi, r-l+1);
        }

        return maxi;
    }
};