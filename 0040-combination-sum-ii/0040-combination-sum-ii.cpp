class Solution {
public:
    void f(vector<int>& arr, int sum, int n, int i, 
            vector<int>& cur, vector<vector<int>>& ans) {
        
        if(sum == 0) {
            ans.push_back(cur);
            return;
        }

        if(sum < 0) return;
        if(i == n) return;

        cur.push_back(arr[i]);
        f(arr, sum - arr[i], n, i + 1, cur, ans);

        cur.pop_back();

        for(int j=i+1;j<n;j++) {
            if(arr[j] != arr[i]) {
                f(arr, sum, n, j, cur, ans);
                break;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();

        vector<vector<int>> ans;
        vector<int> cur;

        f(candidates, target, n, 0, cur, ans);

        return ans;
    }
};