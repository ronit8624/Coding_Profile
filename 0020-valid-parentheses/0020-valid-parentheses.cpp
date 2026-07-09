class Solution {
public:
    bool isClosing(char ch) {
        return ch == ')' || ch == '}' || ch == ']';
    }

    bool matched(char ch1, char ch2) {
        if(ch1 == '(' && ch2 == ')') return true;
        if(ch1 == '{' && ch2 == '}') return true;
        if(ch1 == '[' && ch2 == ']') return true;
        return false;
    }

    bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            if(isClosing(s[i])) {
                if(st.empty()) return false;

                char c = st.top();
                st.pop();

                if(!matched(c, s[i]))
                    return false;
            }
            else {
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};