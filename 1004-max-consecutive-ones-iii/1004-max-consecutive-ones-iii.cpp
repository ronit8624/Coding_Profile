class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxCnt = 0;
        int cntZero = 0;
        int i=0, j=0;

        while(j < n) {
            if(nums[j] == 0) {
                cntZero++;
            }

            if(cntZero > k) {
                if(nums[i] == 0) {
                    cntZero--;
                }

                i++;
            }

            if(cntZero <= k) {
                maxCnt = max(maxCnt, j-i+1);
            }

            j++;
        }

        return maxCnt;
    }
};