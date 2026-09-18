class Solution {
    public int findMaxLength(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int sum = 0, maxi = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] == 0) sum--;
            else sum++;
            if(map.containsKey(sum)) {
                maxi = Math.max(maxi, i - map.get(sum));
            }
            else {
                map.put(sum, i);
            }
        }
        return maxi;
    }
}