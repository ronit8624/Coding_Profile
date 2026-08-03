class Solution {
public:
    bool isValid(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, pair<int, int>>> q;

        q.push({1, {0, 0}});
        vis[0][0] = true;

        while(!q.empty()) {
            auto cell = q.front(); q.pop();
            int cnt = cell.first;
            int row = cell.second.first;
            int col = cell.second.second;

            if(row == n - 1 && col == n - 1) return cnt;

            for(int delRow = -1; delRow <= 1; delRow++) {
                for(int delCol = -1; delCol <= 1; delCol++) {
                    if(delRow == 0 && delCol == 0) continue;

                    int newRow = row + delRow;
                    int newCol = col + delCol;

                    if(isValid(newRow, newCol, n) &&
                       grid[newRow][newCol] == 0 &&
                       !vis[newRow][newCol]) {

                        vis[newRow][newCol] = true;
                        q.push({cnt + 1, {newRow, newCol}});
                    }
                }
            }
        }

        return -1;
    }
};