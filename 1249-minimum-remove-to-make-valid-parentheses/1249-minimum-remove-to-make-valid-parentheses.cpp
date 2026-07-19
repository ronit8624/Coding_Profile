class Solution {
public:
    string minRemoveToMakeValid(string s) {

        int n = s.size();

        string first = "";
        int open = 0;

        for(int i=0;i<n;i++) {

            if(s[i] == '(') {
                open++;
                first.push_back(s[i]);
            }
            else if(s[i] == ')') {

                if(open > 0) {
                    open--;
                    first.push_back(s[i]);
                }
            }
            else {
                first.push_back(s[i]);
            }
        }

        string ans = "";
        int close = 0;

        for(int i=first.size()-1;i>=0;i--) {

            if(first[i] == ')') {
                close++;
                ans.push_back(first[i]);
            }
            else if(first[i] == '(') {

                if(close > 0) {
                    close--;
                    ans.push_back(first[i]);
                }
            }
            else {
                ans.push_back(first[i]);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};