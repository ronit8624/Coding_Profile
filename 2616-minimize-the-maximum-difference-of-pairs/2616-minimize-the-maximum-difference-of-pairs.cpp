class Solution {
public:
    bool isValid(vector<int>& arr, int mid, int p, int n) {
        int i=0;
        int cntPairs = 0;

        while(i < n-1) {
            if(abs(arr[i] - arr[i+1]) <= mid) {
                cntPairs++;
                i += 2;
            }
            else {
                i++;
            }
        }

        return cntPairs >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n-1] - nums[0];
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(isValid(nums, mid, p, n)) {
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