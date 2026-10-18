class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    bool basePalindrome(int num, int base) {
        string ans = "";
        while(num != 0) {
            int digit = num % base;
            ans += digit;
            num = num / base;
        }

        if(isPalindrome(ans)) {
            return true;
        }

        return false;
    }

    bool isStrictlyPalindromic(int n) {
        for(int base = 2; base <= (n - 2); base++) {
            if(!basePalindrome(n, base)) {
                return false;
            }
        }

        return true;
    }
};