class Solution {
    public int minimumRightShifts(List<Integer> nums) {
        int n = nums.size();
        int count = 0;
        int index = 0;

        for(int i=1;i<n;i++) {
            if(nums.get(i) < nums.get(i-1)) {
                count++;
                index = i;
            }
        }

        if(count == 0) return 0;
        if(count > 1) return -1;

        if(nums.get(n-1) < nums.get(0)) {
            return n - index;
        }

        return -1;
    }
}