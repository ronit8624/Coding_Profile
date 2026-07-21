class Solution {
public:
    void expand(string& s, int l, int r, int& start, int& end) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }

        l++;
        r--;

        if(r - l > end - start) {
            start = l;
            end = r;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, end = 0;

        for(int i=0;i<n;i++) {
            expand(s, i, i, start, end);
            expand(s, i, i+1, start, end);
        }

        return s.substr(start, end - start + 1);
    }
};