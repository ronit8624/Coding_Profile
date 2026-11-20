class Solution {
public:
    void fnc(int k, int n, int i, int sum, vector<int>& v1,         vector<vector<int>>& v) {
        if(sum == n && v1.size() == k) {
            v.push_back(v1);
            return;
        }

        if(sum > n || i > 9) return;

        v1.push_back(i);
        fnc(k, n, i+1, sum+i, v1, v);
        v1.pop_back();

        fnc(k, n, i+1, sum, v1, v);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> v;
        vector<int> v1;
        fnc(k, n, 1, 0, v1, v);
        return v;
    }
};