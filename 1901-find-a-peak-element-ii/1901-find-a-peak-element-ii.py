class Solution:
    def findPeakGrid(self, mat: list[list[int]]) -> list[int]:
        n = len(mat)
        m = len(mat[0])
        low = 0
        high = m-1

        while low <= high:
            mid = (low + high) // 2
            
            max_row = 0
            for i in range(n):
                if mat[i][mid] > mat[max_row][mid]:
                    max_row = i

            left_val = -1
            if mid > 0:
                left_val = mat[max_row][mid - 1]
            
            right_val = -1
            if mid < m-1:
                right_val = mat[max_row][mid+1]

            if mat[max_row][mid] > left_val and mat[max_row][mid] > right_val:
                return [max_row, mid]
            elif left_val > mat[max_row][mid]:
                high = mid - 1
            else:
                low = mid + 1
            
        return [-1, -1]
        