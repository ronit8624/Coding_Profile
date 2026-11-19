class Solution {
public:
    int largestSubarraySumMinimized(vector<int> &a, int k) {
        return splitArray(a, k);
    }

    int fnc(int n, vector<int>& nums, int capacityOfPages) {
        int cntStudents = 1;
        int sum = 0;

        for(int i=0;i<n;i++) {
            if(sum + nums[i] <= capacityOfPages) {
                sum += nums[i];
            }
            else {
                cntStudents++;
                sum = nums[i];
            }
        }

        return cntStudents;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        if(k > n) return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int students = fnc(n, nums, mid);

            if(students > k) {
                low = mid + 1;
            }
            else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};