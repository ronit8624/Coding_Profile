class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int cnt = 0;
        int lastFinish = intervals[0][1];

        for(int i=1;i<n;i++) {
            int currStart = intervals[i][0];

            if(currStart < lastFinish) {
                cnt++;
                lastFinish = min(lastFinish, intervals[i][1]);
            }
            else {
                lastFinish = intervals[i][1];
            }
        }

        return cnt;
    }
};