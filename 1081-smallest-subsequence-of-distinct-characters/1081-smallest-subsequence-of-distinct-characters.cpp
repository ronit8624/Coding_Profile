class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();

        vector<int> lastInd(26);
        vector<int> vis(26, false);

        for(int i=0;i<n;i++) {
            lastInd[s[i] - 'a'] = i;
        }

        string ans = "";

        for(int i=0;i<n;i++) {
            char ch = s[i];

            if(vis[ch - 'a']) continue;

            while(!ans.empty() &&
                    ans.back() > ch &&
                    lastInd[ans.back() - 'a'] > i) {
                
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            vis[ch - 'a'] = true;
        }

        return ans;
    }
};