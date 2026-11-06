class Solution:
    def maxScore(self, cardPoints: list[int], k: int) -> int:
        n = len(cardPoints)
        leftSum = 0

        for i in range(k):
            leftSum += cardPoints[i]

        maxSum = leftSum
        rightSum = 0
        rightIndex = n-1

        for i in range(k-1, -1, -1):
            leftSum -= cardPoints[i]
            rightSum += cardPoints[rightIndex]
            rightIndex -= 1

            maxSum = max(maxSum, leftSum + rightSum)
        
        return maxSum

        