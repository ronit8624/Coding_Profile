class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        int n = temperatures.size();
        stack<int> st; // index

        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            if(st.empty()) {
                ans.push_back(0);
            }
            else {
                ans.push_back(st.top() - i);
            }

            st.push(i);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};