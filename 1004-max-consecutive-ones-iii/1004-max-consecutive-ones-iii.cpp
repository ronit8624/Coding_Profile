class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeros = 0;
        int i = 0, j = 0;
        int maxLen = INT_MIN;

        for(int i=0;i<n;i++) {
            if(nums[i] == 0) zeros++;

            while(zeros > k) {
                if(nums[j] == 0) zeros--;
                j++;
            }

            int len = i - j + 1;
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};