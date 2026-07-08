class Solution {
public:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValid(int i, int j, int n, int m) {
        return i >=0 && i < n && j >= 0 && j < m;
    }

    void dfs(int row, int col, int n, int m, vector<vector<char>>& vis, 
             vector<vector<char>>& mat) {
        
        vis[row][col] = 'O';

        for(int i=0;i<4;i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(isValid(newRow, newCol, n, m) &&
               mat[newRow][newCol] == 'O' &&
               vis[newRow][newCol] == 'X') {

                dfs(newRow, newCol, n, m, vis, mat);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<char>> vis(n, vector<char>(m, 'X'));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(i == 0 || i == n-1) {
                    if(board[i][j] == 'O' && vis[i][j] == 'X') {
                        dfs(i, j, n, m, vis, board);
                    }
                }

                if(j == 0 || j == m-1) {
                    if(board[i][j] == 'O' && vis[i][j] == 'X') {
                        dfs(i, j, n, m, vis, board);
                    }
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == 'O' && vis[i][j] == 'X') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};