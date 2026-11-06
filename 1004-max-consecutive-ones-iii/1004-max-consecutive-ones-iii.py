class Solution:
    def longestOnes(self, nums: list[int], k: int) -> int:
        n = len(nums)
        maxi = 0
        zeros = 0
        j = 0

        for i in range(n):
            if nums[i] == 0:
                zeros += 1

            while zeros > k:
                if nums[j] == 0:
                    zeros -= 1
                j += 1

            maxi = max(maxi, i - j + 1)

        return maxi