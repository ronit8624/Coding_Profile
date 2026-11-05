class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& adj, 
                vector<int>& vis) {
        vis[node] = true;

        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();

        unordered_map<int, vector<int>> adj;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, false);
        int count = 0;

        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                count++;
                dfs(i, adj, vis);
            }
        }

        return count;
    }
};