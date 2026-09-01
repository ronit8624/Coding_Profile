class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int len = 0, maxi = 0;
        Map<Character, Integer> freqMap = new HashMap<>();
        int j = 0;

        for (int i = 0; i < n; i++) {
            freqMap.put(s.charAt(i), freqMap.getOrDefault(s.charAt(i), 0) + 1);

            while (freqMap.get(s.charAt(i)) > 1) {
                freqMap.put(s.charAt(j), freqMap.getOrDefault(s.charAt(j), 0) - 1);

                if (freqMap.get(s.charAt(j)) == 0) {
                    freqMap.remove(s.charAt(j));
                }

                j++;
            }

            len = i - j + 1;
            maxi = Math.max(maxi, len);
        }

        return maxi;
    }
}