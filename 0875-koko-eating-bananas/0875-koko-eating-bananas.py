class Solution:
    def getHours(self, piles, mid):
        sum = 0

        for i in range(len(piles)):
            sum += (piles[i] + mid - 1) // mid
        
        return sum

    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        n = len(piles)
        low = 1
        high = max(piles)

        while low <= high:
            mid = low + (high - low) // 2
            hours = self.getHours(piles, mid)

            if hours <= h:
                high = mid - 1
            else:
                low = mid + 1
        
        return low
        