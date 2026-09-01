class Solution {
    public int expand(String s, int l, int r) {
        while(l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
            l--;
            r++;
        }

        return r - l - 1;
    }
    
    public String longestPalindrome(String s) {
        int n = s.length();
        int start = 0, end = 0;

        for(int i=0;i<n;i++) {
            int oddLength = expand(s, i, i);
            int evenLength = expand(s, i, i+1);
            int maxi = Math.max(oddLength, evenLength);

            if(maxi > (end - start + 1)) {
                start = i - (maxi - 1) / 2;
                end = i + maxi / 2;
            }
        }

        return s.substring(start, end + 1);
    }
}