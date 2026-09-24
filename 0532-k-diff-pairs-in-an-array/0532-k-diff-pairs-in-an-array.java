class Solution {
    public int findPairs(int[] nums, int k) {
        Set<Integer> seen = new HashSet<>();
        Set<Integer> pairs = new HashSet<>();

        for(int i=0;i<nums.length;i++) {
            if(seen.contains(nums[i] - k)) {
                pairs.add(nums[i] - k);
            }

            if(seen.contains(nums[i] + k)) {
                pairs.add(nums[i]);
            }

            seen.add(nums[i]);
        }

        return pairs.size();
    }
}