class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        map = {}
        maxi = 0
        j = 0

        for i in range(n):
            map[s[i]] = map.get(s[i], 0) + 1

            while map[s[i]] > 1:
                map[s[j]] -= 1

                if map[s[j]] == 0:
                    del map[s[j]]
                
                j += 1

            maxi = max(maxi, i - j + 1)

        return maxi