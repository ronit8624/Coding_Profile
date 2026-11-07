class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        freq = defaultdict(int)
        maxfreq = 0
        maxlen = 0
        j = 0

        for i in range(n):
            freq[s[i]] += 1
            maxfreq = max(maxfreq, freq[s[i]])

            if (i - j + 1) - maxfreq > k:
                freq[s[j]] -= 1

                if freq[s[j]] == 0:
                    del freq[s[j]]
                
                j += 1
            
            maxlen = max(maxlen, i - j + 1)
        
        return maxlen