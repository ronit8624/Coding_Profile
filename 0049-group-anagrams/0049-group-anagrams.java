class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int n = strs.length;
        Map<String, List<String>> map = new HashMap<>();
        for(int i=0;i<n;i++) {
            char[] chars = strs[i].toCharArray();
            Arrays.sort(chars);
            String key = new String(chars);
            if(!map.containsKey(key)) {
                map.put(key, new ArrayList<>());
            }
            map.get(key).add(strs[i]);
        }
        return new ArrayList<>(map.values());
    }
}