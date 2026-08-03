class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        int lastStart = intervals[0][0];
        int lastEnd = intervals[0][1];

        for(int i = 1; i < n; i++) {
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];

            if(curStart <= lastEnd) {
                lastEnd = max(lastEnd, curEnd);
            }
            else {
                ans.push_back({lastStart, lastEnd});
                lastStart = curStart;
                lastEnd = curEnd;
            }
        }

        ans.push_back({lastStart, lastEnd});

        return ans;
    }
};