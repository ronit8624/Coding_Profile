class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        int maxi = 0, j = 0;

        for(int i=0;i<n;i++) {
            mpp[s[i]]++;

            while(mpp[s[i]] > 1) {
                mpp[s[j]]--;

                if(mpp[s[j]] == 0) {
                    mpp.erase(s[j]);
                }

                j++;
            }

            maxi = max(maxi, i - j + 1);
        }

        return maxi;
    }
};