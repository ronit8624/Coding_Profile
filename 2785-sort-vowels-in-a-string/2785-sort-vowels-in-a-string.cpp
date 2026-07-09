class Solution {
public:
    bool isVowel(char s) {
        return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' ||
                s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U';
    }

    string sortVowels(string s) {
        vector<char> vowels;

        for(int i=0;i<s.size();i++) {
            if(isVowel(s[i])) {
                vowels.push_back(s[i]);
            }
        }

        sort(vowels.begin(), vowels.end());
        int ind = 0;

        for(int i=0;i<s.size();i++) {
            if(isVowel(s[i])) {
                s[i] = vowels[ind];
                ind++;
            }
        }

        return s;
    }
};