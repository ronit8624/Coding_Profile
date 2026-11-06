class Solution:
    def getTotalDays(self, weights, mid, days):
        total = 0
        days = 1

        for i in range(len(weights)):
            if(total + weights[i] <= mid):
                total += weights[i]
            else:
                days += 1
                total = weights[i]
        
        return days

    def shipWithinDays(self, weights: list[int], days: int) -> int:
        low = max(weights)
        high = sum(weights)
        ans = high

        while low <= high:
            mid = low + (high - low) // 2
            totalDays = self.getTotalDays(weights, mid, days)

            if totalDays <= days:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1

        return ans