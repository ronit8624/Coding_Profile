class Solution:
    def getTotalB(self, nums, days, k):
        count = 0
        total = 0
        
        for i in range(len(nums)):
            if nums[i] <= days:
                count += 1
            else:
                total += count // k
                count = 0

        total += count // k
        return total
    
    def minDays(self, bloomDay: list[int], m: int, k: int) -> int:
        if m * k > len(bloomDay):
            return -1
        
        low = min(bloomDay)
        high = max(bloomDay)

        while low <= high:
            mid = low + (high - low) // 2
            totalB = self.getTotalB(bloomDay, mid, k)

            if(totalB >= m):
                high = mid - 1
            else:
                low = mid + 1
        
        return low
        