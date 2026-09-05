class Solution {
    public int findPermutationDifference(String s, String t) {
        int[] indices = new int[26];

        for(int i=0;i<s.length();i++) {
            indices[s.charAt(i) - 'a'] = i;
        }

        int ans = 0;

        for(int i=0;i<t.length();i++) {
            ans += Math.abs(i - indices[t.charAt(i) - 'a']);
        }

        return ans;
    }
}