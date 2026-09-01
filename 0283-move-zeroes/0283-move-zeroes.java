class Solution {
    void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int zero = -1;

        for(int i=0;i<n;i++) {
            if(nums[i] == 0) {
                zero = i;
                break;
            }
        }

        if(zero == -1) return;

        for(int i=zero+1;i<n;i++) {
            if(nums[i] != 0) {
                swap(nums, zero, i);
                zero++;
            }
        }
    }
}