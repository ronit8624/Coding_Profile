class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> arr = temperatures;
        int n = arr.size();
        stack<int> st;
        vector<int> ans;

        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                ans.push_back(0);
                st.push(i);
            }
            else {
                int diff = st.top() - i;
                ans.push_back(diff);
                st.push(i);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};