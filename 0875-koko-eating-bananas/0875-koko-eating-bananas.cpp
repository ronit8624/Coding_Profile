class Solution {
public:
    long long f(vector<int>& arr, int mid) {
        int n = arr.size();
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            ans += (arr[i] + mid - 1) / mid;
        }

        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long totalHrs = f(piles, mid);

            if(totalHrs <= h) {
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