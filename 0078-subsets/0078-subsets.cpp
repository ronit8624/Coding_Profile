class Solution {
public:
    void fnc(vector<int>& nums, int n, int i, vector<int>& list, vector<vector<int>>& ans) {
            if(i == n) {
                ans.push_back(list);
                return;
            }

            fnc(nums, n, i+1, list, ans);

            list.push_back(nums[i]);
            fnc(nums, n, i+1, list, ans);

            list.pop_back();
        }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
            vector<vector<int>> ans;
            vector<int> list;

            fnc(nums, n, 0, list, ans);
            return ans;
    }
};