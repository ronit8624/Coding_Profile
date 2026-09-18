class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        int jumps = 0, maxReach = 0, currEnd = 0;

        for(int i=0;i<n-1;i++) {
            maxReach = Math.max(maxReach, i + nums[i]);

            if(i == currEnd) {
                jumps++;
                currEnd = maxReach;
            }
        }

        return jumps;
    }
}