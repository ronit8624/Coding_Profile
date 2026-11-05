class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) {
                    fresh++;
                }
                else if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int time = 0;

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        while(!q.empty() && fresh > 0) {
            int size = q.size();

            for(int i=0;i<size;i++) {
                auto cell = q.front();
                q.pop();

                int row = cell.first;
                int col = cell.second;

                for(int j=0;j<4;j++) {
                    int nrow = row + delRow[j];
                    int ncol = col + delCol[j];

                    if(isValid(nrow, ncol, n, m) &&
                        grid[nrow][ncol] == 1) {
                        
                        grid[nrow][ncol] = 2;
                        fresh--;
                        q.push({nrow, ncol});
                    }
                }
            }

            time++;
        }

        return fresh == 0 ? time : -1;
    }
};