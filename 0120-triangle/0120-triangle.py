class Solution:
    def fnc(self, i, j, mat, dp):
        n = len(mat)

        if i == n-1:
            return mat[i][j]

        if dp[i][j] != -1:
            return dp[i][j]

        bottom = mat[i][j] + self.fnc(i + 1, j, mat, dp)
        bottom_right = mat[i][j] + self.fnc(i + 1, j + 1, mat, dp)

        dp[i][j] = min(bottom, bottom_right)

        return dp[i][j]

    def minimumTotal(self, triangle: list[list[int]]) -> int:
        n = len(triangle)

        dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

        for j in range(n):
            dp[n-1][j] = triangle[n-1][j]
        
        for i in range(n-2, -1, -1):
            for j in range(i + 1):
                bottom = triangle[i][j] + dp[i + 1][j]
                bottom_right = triangle[i][j] + dp[i + 1][j + 1]
                dp[i][j] = min(bottom, bottom_right)

        return dp[0][0]