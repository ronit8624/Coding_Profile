class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n = s.size();
        map<char, int> freq;

        for(int i = 0; i < n; i++) {
            freq[s[i]] = i;
        }

        int start = 0;
        int end = freq[s[0]];

        for(int i = 0; i < n; i++) {
            end = max(end, freq[s[i]]);

            if(i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};