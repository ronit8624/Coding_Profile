class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];
            mp[ch]++;

            while (mp[ch] > 1) {
                char leftChar = s[left];
                mp[leftChar]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};