class Solution {
public:
    int getNextInd(int low, int currJobEnd, vector<vector<int>>& arr) {
        int high = arr.size() - 1;
        int ans = 1e9;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid][0] >= currJobEnd) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
    int f(int ind, vector<vector<int>>& arr, vector<int>& dp) {
        if(ind >= arr.size()) return 0;
        if(dp[ind] != -1) return dp[ind];

        int next = getNextInd(ind + 1, arr[ind][1], arr);
        int notTake = f(ind + 1, arr, dp);
        int take = arr[ind][2] + f(next, arr, dp);

        return dp[ind] = max(notTake, take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> arr(n, vector<int>(3, 0));

        for(int i=0;i<n;i++) {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        sort(arr.begin(), arr.end());

        vector<int> dp(n, -1);

        return f(0, arr, dp);
    }
};