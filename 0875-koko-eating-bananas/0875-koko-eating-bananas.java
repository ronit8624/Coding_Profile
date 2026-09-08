class Solution {
    private long getTotalHours(int[] piles, int mid) {
        long hours = 0;

        for(int i = 0; i < piles.length; i++) {
            long completeUnit = (piles[i] + (long)mid - 1) / mid;
            hours += completeUnit;
        }

        return hours;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int low = 1;
        int high = 0;

        for(int i = 0; i < piles.length; i++) {
            high = Math.max(high, piles[i]);
        }

        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            long totalHours = getTotalHours(piles, mid);

            if(totalHours <= h) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
}