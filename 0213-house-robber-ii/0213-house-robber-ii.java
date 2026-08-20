class Solution {
    public int houseRobber(List<Integer> nums) {
        int n = nums.size();

        int[] dp = new int[n + 1];
        Arrays.fill(dp, 0);

        dp[0] = 0;
        dp[1] = nums.get(0);

        for(int ind=2;ind<=n;ind++) {
            int notTake = dp[ind-1];
            int take = nums.get(ind - 1) + dp[ind-2];

            dp[ind] = Math.max(take, notTake);
        }

        return dp[n];
    }

    public int rob(int[] nums) {
        int n = nums.length;

        if(n == 1) return nums[0];

        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            if(i != n - 1) {
                list1.add(nums[i]);
            }

            if(i != 0) {
                list2.add(nums[i]);
            }
        }

        return Math.max(houseRobber(list1), houseRobber(list2));
    }
}