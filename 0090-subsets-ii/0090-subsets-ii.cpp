class Solution {
public:
    void f(vector<int>& nums, int i, vector<int>& cur,
           vector<vector<int>>& ans) {

        ans.push_back(cur);

        for(int j = i; j < nums.size(); j++) {

            if(j > i && nums[j] == nums[j - 1])
                continue;

            cur.push_back(nums[j]);

            f(nums, j + 1, cur, ans);

            cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> cur;

        f(nums, 0, cur, ans);

        return ans;
    }
};