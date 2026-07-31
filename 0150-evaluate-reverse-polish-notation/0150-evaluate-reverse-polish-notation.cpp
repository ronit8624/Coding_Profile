class Solution {
public:
    bool isSymbol(string s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;

        for(int i=0;i<n;i++) {
            if(!isSymbol(tokens[i])) {
                st.push(stoi(tokens[i]));
            }
            else {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                if(tokens[i] == "+") st.push(a + b);
                else if(tokens[i] == "*") st.push(a * b);
                else if(tokens[i] == "-") st.push(a - b);
                else st.push(a / b);
            }
        }

        return st.top();
    }
};