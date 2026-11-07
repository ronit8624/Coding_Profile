class Solution:
    def totalFruit(self, fruits: list[int]) -> int:
        n = len(fruits)
        freq = defaultdict(int)
        j = 0
        count = 0

        for i in range(n):
            freq[fruits[i]] += 1

            while len(freq) > 2:
                freq[fruits[j]] -= 1

                if freq[fruits[j]] == 0:
                    del freq[fruits[j]]
                
                j += 1
            
            count = max(count, i - j + 1)
        
        return count