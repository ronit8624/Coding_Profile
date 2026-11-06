class Solution:
    def f(self, i, j, grid, dp):
        if i == 0 and j == 0:
            return grid[i][j]
        if i < 0 or j < 0:
            return float('inf')
        if dp[i][j] != -1:
            return dp[i][j]

        top = grid[i][j] + self.f(i-1, j, grid, dp)
        left = grid[i][j] + self.f(i, j-1, grid, dp)
        dp[i][j] = min(top, left)

        return dp[i][j]

    def minPathSum(self, grid: list[list[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        dp = [[0 for _ in range(m)] for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if i == 0 and j == 0:
                    dp[i][j] = grid[i][j]
                else:
                    top = float('inf')
                    left = float('inf')

                    if i > 0:
                        top = grid[i][j] + dp[i-1][j]
                    if j > 0:
                        left = grid[i][j] + dp[i][j-1]

                    dp[i][j] = min(top, left)
        
        return dp[n-1][m-1]

