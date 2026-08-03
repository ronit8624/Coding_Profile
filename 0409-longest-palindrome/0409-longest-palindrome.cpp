class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freqMap;

        for(char ch : s) {
            freqMap[ch]++;
        }

        int longest = 0;
        int oddCnt = 0;

        for(auto it : freqMap) {
            int freq = it.second;

            if(freq % 2 == 0) {
                longest += freq;
            }
            else {
                longest += freq - 1;
                oddCnt++;
            }
        }

        if(oddCnt > 0) longest++;

        return longest;
    }
};