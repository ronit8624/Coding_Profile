class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for(int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        int maxi = 0;

        for(auto it : st) {
            if(st.find(it - 1) == st.end()) {
                int num = it;
                int cnt = 1;

                while(st.find(num + 1) != st.end()) {
                    cnt++;
                    num++;
                }

                maxi = max(maxi, cnt);
            }
        }

        return maxi;
    }
};
