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

        // if i am deciding not to take any element so i should not take, the element throughout, means if the element occurres more than one time and i have decided to not take it , i shoukd not take the same element afterwards also because if i take that will generate the same sequence eventually.
        
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