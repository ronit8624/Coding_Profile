class Solution {
public:
    bool isValid(int mid, vector<int>& nums, int p) {
        int i = 0, cnt = 0;

        while(i < nums.size() - 1) {
            if(abs(nums[i] - nums[i + 1]) <= mid) {
                cnt++;
                i += 2;
            }
            else i++;
        }

        return cnt >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n-1] - nums[0];
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(isValid(mid, nums, p)) {
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