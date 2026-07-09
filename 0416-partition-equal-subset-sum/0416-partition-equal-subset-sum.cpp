class Solution {
public:
    bool isSubsetSum(vector<int> arr, int target) {
        int n = arr.size();
        vector<bool> prev(target+1, false);
        vector<bool> curr(target+1, false);
        prev[0] = curr[0] = true;

        if(target >= arr[0]) {
            prev[arr[0]] = true;
        }

        for(int ind = 1; ind < n; ind++) {
            for(int i = 1; i <= target; i++) {
                bool not_take = prev[i];

                bool take = false;
                if(i >= arr[ind]) {
                    take = prev[i - arr[ind]];
                }

                curr[i] = take || not_take;
            }

            prev = curr;
        }

        return prev[target];
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for(int i=0;i<n;i++) {
            totalSum += nums[i];
        }

        if(totalSum % 2 != 0) 
            return false;
        else {
            int k = totalSum / 2;
            return isSubsetSum(nums, k);
        }
    }
};