class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while(left < right) {
            char l = s[left];
            char r = s[right];

            if(!isAlphaNum(l)) {
                left++;
            }
            else if(!isAlphaNum(r)) {
                right--;
            }
            else {
                if(tolower(l) != tolower(r)) {
                    return false;
                }

                left++;
                right--;
            }
        }

        return true;
    }

    bool isAlphaNum(char c) {
        return (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z') ||
               (c >= '0' && c <= '9');
    }
};