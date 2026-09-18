class Solution {
    public String minWindow(String s, String t) {
        int mini = Integer.MAX_VALUE;
        int sInd = -1;

        int[] hash = new int[256];

        for(char c : t.toCharArray()) {
            hash[c]++;
        }

        int count = 0;
        int l = 0, r = 0;

        while(r < s.length()) {
            if(hash[s.charAt(r)] > 0) {
                count++;
            }

            hash[s.charAt(r)]--;

            while(count == t.length()) {
                if(r - l + 1 < mini) {
                    mini = r - l + 1;
                    sInd = l;
                }

                hash[s.charAt(l)]++;
                if(hash[s.charAt(l)] > 0) {
                    count--;
                }

                l++;
            }

            r++;
        }

        if(sInd == -1) return "";
        return s.substring(sInd, sInd + mini);
    }
}