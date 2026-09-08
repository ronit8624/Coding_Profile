class Solution {
    public int returnToBoundaryCount(int[] nums) {
        int n = nums.length;
        int cnt = 0, sum = 0;

        for(int i=0;i<n;i++) {
            sum += nums[i];

            if(sum == 0) {
                cnt++;
            }
        }

        return cnt;
    }
}