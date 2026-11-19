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

        f(arr, sum, n, i + 1, cur, ans);

        cur.push_back(arr[i]);
        f(arr, sum - arr[i], n, i, cur, ans);

        cur.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();

        vector<vector<int>> ans;
        vector<int> cur;

        f(candidates, target, n, 0, cur, ans);

        return ans;
    }
};