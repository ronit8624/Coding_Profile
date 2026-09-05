class Solution {
    private boolean isVowel(char s) {
        return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' ||
               s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U';
    }

    public String sortVowels(String s) {
        int n = s.length();
        ArrayList<Character> vowels = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            if(isVowel(s.charAt(i))) {
                vowels.add(s.charAt(i));
            }
        }

        Collections.sort(vowels);

        int ind = 0;
        StringBuilder str = new StringBuilder(s);

        for(int i = 0; i < n; i++) {
            if(isVowel(str.charAt(i))) {
                str.setCharAt(i, vowels.get(ind++));
            }
        }

        return str.toString();
    }
}