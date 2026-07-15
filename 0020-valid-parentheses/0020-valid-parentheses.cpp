class Solution {
public:
    bool isClosing(char ch) {
        return ch == ')' || ch == '}' || ch == ']';
    }
    bool isMatched(char open, char close) {
        return (open == '(' && close == ')') ||
                (open == '{' && close == '}') ||
                (open == '[' && close == ']');
    }
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;

        for(int i=0;i<n;i++) {
            if(isClosing(s[i])) {
                if(st.empty()) return false;
                else {
                    char ch = st.top();

                    if(!isMatched(ch, s[i])) {
                        return false;
                    }
                    else {
                        st.pop();
                    }
                }
            }
            else {
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};