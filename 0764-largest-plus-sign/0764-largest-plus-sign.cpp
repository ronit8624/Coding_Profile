class Solution {
public:
    vector<vector<int>> buildGrid(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));

        for(auto &mine : mines) {
            grid[mine[0]][mine[1]] = 0;
        }

        return grid;
    }

    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        if(n == 1) return 0;
        
        vector<vector<int>> grid = buildGrid(n, mines);

        vector<vector<int>> lTR(n, vector<int>(n));
        vector<vector<int>> rTL(n, vector<int>(n));
        vector<vector<int>> tTB(n, vector<int>(n));
        vector<vector<int>> bTT(n, vector<int>(n));

        // Left -> Right
        for(int i = 0; i < n; i++) {
            int runningSum = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0)
                    runningSum = 0;
                else
                    runningSum += grid[i][j];

                lTR[i][j] = runningSum;
            }
        }

        // Right -> Left
        for(int i = 0; i < n; i++) {
            int runningSum = 0;
            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j] == 0)
                    runningSum = 0;
                else
                    runningSum += grid[i][j];

                rTL[i][j] = runningSum;
            }
        }

        // Top -> Bottom
        for(int j = 0; j < n; j++) {
            int runningSum = 0;
            for(int i = 0; i < n; i++) {
                if(grid[i][j] == 0)
                    runningSum = 0;
                else
                    runningSum += grid[i][j];

                tTB[i][j] = runningSum;
            }
        }

        // Bottom -> Top
        for(int j = 0; j < n; j++) {
            int runningSum = 0;
            for(int i = n - 1; i >= 0; i--) {
                if(grid[i][j] == 0)
                    runningSum = 0;
                else
                    runningSum += grid[i][j];

                bTT[i][j] = runningSum;
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int minLen = min(
                    min(lTR[i][j], rTL[i][j]),
                    min(tTB[i][j], bTT[i][j])
                );

                ans = max(ans, minLen);
            }
        }

        return ans;
    }
};