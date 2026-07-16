class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string st;

        for(int i=0;i<n;i++) {
            char ch = s[i];
            
            if(!st.empty() && abs(st.back() - ch) == 32) {
                st.pop_back();
            }
            else {
                st.push_back(ch);
            }
        }

        return st;
    }
};