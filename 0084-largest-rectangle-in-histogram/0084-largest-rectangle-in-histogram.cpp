class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                int ind = st.top();
                st.pop();

                int pse = st.empty() ? -1 : st.top();
                int nse = i;

                int area = heights[ind] * (nse - pse - 1);
                maxi = max(maxi, area);
            }

            st.push(i);
        }

        while(!st.empty()) {
            int ind = st.top();
            st.pop();

            int pse = st.empty() ? -1 : st.top();
            int nse = n;

            int area = heights[ind] * (nse - pse - 1);
            maxi = max(maxi, area);
        }

        return maxi;
    }
};