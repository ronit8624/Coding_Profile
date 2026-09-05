class Solution {
    private boolean getKSetBits(int n, int k) {
        int ans = 0;

        while(n > 0) {
            n = n & (n - 1);
            ans++;
        }

        return ans == k;
    }

    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        int ans = 0;
        int n = nums.size();

        for(int i=0;i<n;i++) {
            boolean kSetBits = getKSetBits(i, k);

            if(kSetBits == true) {
                ans += nums.get(i);
            }
        }

        return ans;
    }
}