class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, end = 0;

        for(int i = 0; i < n; i++) {
            int oddLength = f(s, i, i);
            int evenLength = f(s, i, i + 1);
            int len = max(oddLength, evenLength);

            if(len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }

    int f(string s, int l, int r) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }

        return r - l - 1;
    }
};