class Solution {
public:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

    void dfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<bool>>& vis, int n, int m) {

        vis[row][col] = true;

        for(int i = 0; i < 4; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(isValid(newRow, newCol, n, m) &&
               !vis[newRow][newCol] &&
               grid[newRow][newCol] == '1') {

                dfs(newRow, newCol, grid, vis, n, m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid, vis, n, m);
                }
            }
        }

        return cnt;
    }
};