class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> dis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        while(!q.empty()) {
            auto cell = q.front();
            int row = cell.first.first;
            int col = cell.first.second;
            int steps = cell.second;
            dis[row][col] = steps;
            q.pop();

            for(int i=0;i<4;i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(isValid(nrow, ncol, n, m) &&
                   !vis[nrow][ncol]) {
                    
                    q.push({{nrow, ncol}, steps+1});
                    vis[nrow][ncol] = true;
                }
            }
        }

        return dis;
    }
};