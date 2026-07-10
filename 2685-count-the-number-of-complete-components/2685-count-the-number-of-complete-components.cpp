class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool>& vis, vector<int>& comp) {
        vis[node] = true;
        comp.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, comp);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i, adj, vis, comp);

                int sz = comp.size();
                bool complete = true;

                for (auto node : comp) {
                    if (adj[node].size() != sz - 1) {
                        complete = false;
                        break;
                    }
                }

                if (complete) cnt++;
            }
        }

        return cnt;
    }
};