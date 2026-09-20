class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n-k+1];
        int l = 0, r = 0;
        int index = 0;
        Deque<Integer> dq = new ArrayDeque<>();

        while(r < n) {
            while(!dq.isEmpty() && nums[dq.peekLast()] <= nums[r]) {
                dq.pollLast();
            }

            dq.addLast(r);

            if(dq.peekFirst() < l) {
                dq.pollFirst();
            }

            if(r - l + 1 >= k) {
                ans[index++] = nums[dq.peekFirst()];
                l++;
            }

            r++;
        }

        return ans;
    }
}