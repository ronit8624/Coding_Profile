class Solution {
public:

    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;
        int time = 0;

        queue<pair<int, int>> q;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {

                if(grid[i][j] == 2) {
                    q.push({i, j});
                }

                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while(!q.empty() && fresh > 0) {

            int size = q.size();

            for(int i=0;i<size;i++) {

                auto cell = q.front();

                int row = cell.first;
                int col = cell.second;

                q.pop();

                for(int i=0;i<4;i++) {

                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];

                    if(isValid(nRow, nCol, n, m) &&
                        grid[nRow][nCol] == 1) {
                        
                        grid[nRow][nCol] = 2;
                        fresh--;
                        q.push({nRow, nCol});
                    }
                }
            }

            time++;
        }

        if(fresh == 0) return time;
        return -1;
    }
};