class Solution {
public:
    using P = pair<int, pair<int, int>>;

    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> maxDiff(n, vector<int>(m, 1e9));
        maxDiff[0][0] = 0;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            auto cell = pq.top();
            pq.pop();

            int diff = cell.first;
            int row = cell.second.first;
            int col = cell.second.second;

            if(row == n-1 && col == m-1) return diff;

            for(int i=0;i<4;i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(isValid(nrow, ncol, n, m)) {
                    int currDiff = abs(heights[nrow][ncol] -
                                        heights[row][col]);
                    
                    if(max(diff, currDiff) < maxDiff[nrow][ncol]) {
                        maxDiff[nrow][ncol] = max(diff, currDiff);
                        pq.push({max(diff, currDiff), {nrow, ncol}});
                    }
                }
            }
        }

        return -1;
    }
};