class Solution {
public:
    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    void f(int ind, string& s, string& temp, vector<string>& ans) {
        if(ind == s.size()) {
            ans.push_back(temp);
            return;
        }

        if(isDigit(s[ind])) {
            temp.push_back(s[ind]);
            f(ind + 1, s, temp, ans);
            temp.pop_back();
        }
        else {
            temp.push_back(tolower(s[ind]));
            f(ind + 1, s, temp, ans);
            temp.pop_back();

            temp.push_back(toupper(s[ind]));
            f(ind + 1, s, temp, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string temp;
        f(0, s, temp, ans);
        return ans;
    }
};