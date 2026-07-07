class Solution {
public:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int iniColor = image[sr][sc];

        queue<pair<int, int>> q;
        q.push({sr, sc});

        vis[sr][sc] = true;
        image[sr][sc] = color;

        while(!q.empty()) {
            auto cell = q.front();
            q.pop();

            int row = cell.first;
            int col = cell.second;

            for(int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(isValid(newRow, newCol, n, m) &&
                   !vis[newRow][newCol] &&
                   image[newRow][newCol] == iniColor) {

                    vis[newRow][newCol] = true;
                    image[newRow][newCol] = color;
                    q.push({newRow, newCol});
                }
            }
        }

        return image;
    }
};