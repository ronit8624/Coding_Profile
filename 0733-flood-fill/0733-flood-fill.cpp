class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        
        int iniColor = image[sr][sc];
        if(iniColor == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        image[sr][sc] = color;

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        while(!q.empty()) {
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
                        image[nrow][ncol] == iniColor) {
                        
                        image[nrow][ncol] = color;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        return image;
    }
};