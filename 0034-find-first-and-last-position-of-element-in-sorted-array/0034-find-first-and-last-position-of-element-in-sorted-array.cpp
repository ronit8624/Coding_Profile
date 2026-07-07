class Solution {
public:
    int getFirst(vector<int>& nums, int n, int target) {
        int ans = -1;
        int low = 0, high = n-1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int getLast(vector<int>& nums, int n, int target) {
        int ans = -1;
        int low = 0, high = n-1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = getFirst(nums, n, target);
        int last = getLast(nums, n, target);
        return {first, last};
    }
};