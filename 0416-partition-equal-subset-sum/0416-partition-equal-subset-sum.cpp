class Solution {
private:
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

        for(int tar=0; tar<=target; tar++) {
            if(tar == 0) dp[0][tar] = true;
            else dp[0][tar] = (tar == arr[0]);
        }

        for(int ind = 1; ind < n; ind++) {
            for(int tar = 0; tar <= target; tar++) {
                bool notTake = dp[ind - 1][tar];
                bool take = 0;

                if(tar >= arr[ind]) {
                    take = dp[ind - 1][tar - arr[ind]];
                }

                dp[ind][tar] = take || notTake;
            }
        }

        return dp[n-1][target];
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int ind = 0; ind < n; ind++) {
            sum += nums[ind];
        }

        if(sum % 2 != 0) {
            return false;
        }
        else {
            int k = sum / 2;
            return isSubsetSum(nums, k);
        }
    }
};