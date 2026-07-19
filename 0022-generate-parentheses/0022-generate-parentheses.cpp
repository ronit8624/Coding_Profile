class Solution {
public:
    void f(int n, int open, int close, string str, vector<string>& ans) {
        if(open == close && open + close == (2 * n)) {
            ans.push_back(str);
            return;
        }

        if(open < n) {
            f(n, open + 1, close, str + '(', ans);
        }
        if(open > close) {
            f(n, open, close + 1, str + ')', ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(n, 0, 0, "", ans);
        return ans;
    }
};