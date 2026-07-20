class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0, left = 0;
        unordered_map<char,int> mp;

        for(int right = 0; right < n; right++) {
            char ch = s[right];
            mp[ch]++;

            while(mp[ch] > 1) {
                char leftChar = s[left];
                mp[leftChar]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};