class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (ch != ']') {
                st.push(ch);
            }
            else {
                string str = "";

                while (st.top() != '[') {
                    str = st.top() + str;
                    st.pop();
                }

                st.pop();

                string num = "";

                while (!st.empty() && isdigit(st.top())) {
                    num = st.top() + num;
                    st.pop();
                }

                int repeat = stoi(num);

                string repeated = "";

                for (int j = 0; j < repeat; j++) {
                    repeated += str;
                }

                for (int j = 0; j < repeated.size(); j++) {
                    st.push(repeated[j]);
                }
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};