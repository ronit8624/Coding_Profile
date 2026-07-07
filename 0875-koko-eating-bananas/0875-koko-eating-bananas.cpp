class Solution {
public:
    long long f(vector<int>& nums, int n, int mid) {
        long long sum = 0;

        for(int i=0;i<n;i++) {
            sum += (ceil)((double) nums[i] / mid);
        }

        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans = -1;

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long complete = f(piles, n, mid);

            if(complete <= h) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};