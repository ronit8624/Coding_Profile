class Solution {
    private int kadanesMin(int[] nums, int n) {
        int sum = nums[0];
        int minSum = nums[0];
        for(int i=1;i<n;i++) {
            sum = Math.min(sum + nums[i], nums[i]);
            minSum = Math.min(minSum, sum);
        }
        return minSum;
    }
    private int kadanesMax(int[] nums, int n) {
        int sum = nums[0];
        int maxSum = nums[0];
        for(int i=1;i<n;i++) {
            sum = Math.max(sum + nums[i], nums[i]);
            maxSum = Math.max(maxSum, sum);
        }
        return maxSum;
    }
    public int maxSubarraySumCircular(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
        }
        int minSum = kadanesMin(nums, n);
        int maxSum = kadanesMax(nums, n);
        int circularSum = sum - minSum;
        if(maxSum > 0) {
            return Math.max(maxSum, circularSum);
        }
        return maxSum;
    }
}