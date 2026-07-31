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
        stack<char> st;

        for(char ch : s) {
            if(isClosing(ch)) {
                if(st.empty()) return false;

                char open = st.top();
                st.pop();

                if(!isMatched(open, ch))
                    return false;
            }
            else {
                st.push(ch);
            }
        }

        return st.empty();
    }
};