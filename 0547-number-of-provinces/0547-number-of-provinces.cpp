class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;

        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        vector<int> adj[N];

        // adj list
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<int> vis(N, 0);
        int cnt = 0;

        for(int i=0;i<N;i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, adj, vis);
            }
        }

        return cnt;
    }
};