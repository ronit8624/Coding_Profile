class Solution {
public:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void dfs(int row, int col, vector<vector<char>>& board, 
                vector<vector<int>>& vis, int n, int m) {
        
        vis[row][col] = true;

        for(int i=0;i<4;i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(isValid(nrow, ncol, n, m) &&
                !vis[nrow][ncol] &&
                board[nrow][ncol] == 'O') {
                
                dfs(nrow, ncol, board, vis, n, m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, false));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {

                if(i == 0 || i == n-1) {
                    if(board[i][j] == 'O') {
                        dfs(i, j, board, vis, n, m);
                    }
                }

                if(j == 0 || j == m-1) {
                    if(board[i][j] == 'O') {
                        dfs(i, j, board, vis, n, m);
                    }
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};