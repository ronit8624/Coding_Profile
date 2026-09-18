class Solution {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        Set<Integer> set = new HashSet<>();

        for(int i=0;i<n;i++) {
            set.add(nums[i]);
        }

        int maxi = 0;

        for(int num : set) {
            if(!set.contains(num -1)) {
                int curr = num;
                int count = 1;

                while(set.contains(curr + 1)) {
                    curr++;
                    count++;
                }

                maxi = Math.max(maxi, count);
            }
        }

        return maxi;
    }
}