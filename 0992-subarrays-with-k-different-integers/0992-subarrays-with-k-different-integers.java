class Solution {

    private int atMostK(int[] nums, int k) {
        int count = 0;
        Map<Integer, Integer> freqMap = new HashMap<>();
        int left = 0;

        for(int right = 0; right < nums.length; right++) {

            freqMap.put(nums[right], freqMap.getOrDefault(nums[right], 0) + 1);

            while(freqMap.size() > k) {

                freqMap.put(nums[left], freqMap.get(nums[left]) - 1);

                if(freqMap.get(nums[left]) == 0) {
                    freqMap.remove(nums[left]);
                }

                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

    public int subarraysWithKDistinct(int[] nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
}