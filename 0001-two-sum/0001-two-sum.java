class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;

        int[] temp = new int[n];
        for(int i = 0; i < n; i++) {
            temp[i] = nums[i];
        }

        Arrays.sort(nums);

        int i = 0, j = n - 1;
        int ind1 = -1, ind2 = -1;
        int el1 = Integer.MIN_VALUE;
        int el2 = Integer.MIN_VALUE;

        while(i < j) {
            int sum = nums[i] + nums[j];

            if(sum == target) {
                el1 = nums[i];
                el2 = nums[j];
                break;
            }
            else if(sum < target) {
                i++;
            }
            else {
                j--;
            }
        }

        for(int ind = 0; ind < n; ind++) {
            if(temp[ind] == el1 && ind1 == -1) {
                ind1 = ind;
            }
            else if(temp[ind] == el2 && ind != ind1) {
                ind2 = ind;
            }
        }

        return new int[]{ind1, ind2};
    }
}