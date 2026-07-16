class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> sst;
        vector<char> tst;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '#') {
                if(!sst.empty()) sst.pop_back();
            } else {
                sst.push_back(s[i]);
            }
        }

        for(int i = 0; i < t.size(); i++) {
            if(t[i] == '#') {
                if(!tst.empty()) tst.pop_back();
            } else {
                tst.push_back(t[i]);
            }
        }

        return sst == tst;
    }
};