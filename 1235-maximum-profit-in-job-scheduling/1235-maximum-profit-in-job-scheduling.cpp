class Solution {
public:
    int getNextInd(vector<vector<int>>& arr, int low, int currJobEnd, int n) {
        int high = n - 1;
        int ans = n;

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

    int f(int i, vector<vector<int>>& arr, int n, vector<int>& dp) {
        if(i >= n) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int next = getNextInd(arr, i + 1, arr[i][1], n);

        int take = arr[i][2] + f(next, arr, n, dp);
        int notTake = f(i + 1, arr, n, dp);

        return dp[i] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<vector<int>> arr(n, vector<int>(3));

        for(int i = 0; i < n; i++) {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        sort(arr.begin(), arr.end());

        vector<int> dp(n, -1);

        return f(0, arr, n, dp);
    }
};