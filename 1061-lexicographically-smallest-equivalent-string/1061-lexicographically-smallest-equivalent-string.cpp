class Solution {
public:
    char dfs(unordered_map<char, vector<char>>& adj, char ch, vector<int>& vis) {
        vis[ch - 'a'] = 1;
        char minChar = ch;

        for(auto it : adj[ch]) {
            if(!vis[it - 'a']) {
                minChar = min(minChar, dfs(adj, it, vis));
            }
        }

        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        int m = baseStr.size();

        unordered_map<char, vector<char>> adj;

        for(int i=0;i<n;i++) {
            int u = s1[i];
            int v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string res;

        for(int i=0;i<m;i++) {
            char ch = baseStr[i];
            vector<int> vis(26, 0);

            char minChar = dfs(adj, ch, vis);
            res.push_back(minChar);
        }

        return res;
    }
};