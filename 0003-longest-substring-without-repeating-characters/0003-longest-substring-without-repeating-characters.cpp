class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> freqMap;
        int j=0, maxi = 0;

        for(int i=0;i<n;i++) {
            freqMap[s[i]]++;

            while(freqMap[s[i]] > 1) {
                freqMap[s[j]]--;

                if(freqMap[s[j]] == 0) {
                    freqMap.erase(s[j]);
                }

                j++;
            }

            int len = i - j + 1;
            maxi = max(maxi, len);
        }

        return maxi;
    }
};