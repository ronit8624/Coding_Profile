class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        n = len(matrix)
        m = len(matrix[0])
        low = 0
        high = (n * m) - 1

        while low <= high:
            mid = low + (high - low) // 2
            x = mid // m
            y = mid % m

            if matrix[x][y] == target:
                return True
            elif matrix[x][y] < target:
                low = mid + 1
            else:
                high = mid - 1
        
        return False