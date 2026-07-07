class Solution {
public:
    int f(vector<int>& nums, int n, int k, int mid) {
        int cntB = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] <= mid) {
                cnt++;

                if(cnt == k) {
                    cntB++;
                    cnt = 0;
                }
            }
            else {
                cnt = 0;
            }
        }

        return cntB;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL * k * m > n) return -1;

        int ans = -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int cntB = f(bloomDay, n, k, mid);

            if(cntB >= m) {
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