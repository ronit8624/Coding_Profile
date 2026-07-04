class Solution {
public:
    using P = pair<int, pair<int, int>>;

    bool isValid(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0] = true;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({1, {0, 0}});

        while(!pq.empty()) {
            auto cell = pq.top();
            int count = cell.first;

            int row = cell.second.first;
            int col = cell.second.second;

            pq.pop();

            if(row == n-1 && col == n-1) {
                return count;
            }

            for(int delRow = -1; delRow <= 1; delRow++) {
                for(int delCol = -1; delCol <= 1; delCol++) {

                    int newRow = row + delRow;
                    int newCol = col + delCol;

                    if(isValid(newRow, newCol, n) &&
                       !vis[newRow][newCol] &&
                       grid[newRow][newCol] == 0) {

                        vis[newRow][newCol] = true;
                        pq.push({count + 1, {newRow, newCol}});
                    }
                }
            }
        }

        return -1;
    }
};