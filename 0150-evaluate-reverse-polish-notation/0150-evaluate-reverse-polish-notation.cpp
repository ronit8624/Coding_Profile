class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;

        for(int i=0;i<n;i++) {
            if(tokens[i] == "+") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(a + b);
            }
            else if(tokens[i] == "-") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b - a);
            }
            else if(tokens[i] == "*") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(a * b);
            }
            else if(tokens[i] == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b / a);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }

        int ans = st.top();
        return ans;
    }
};