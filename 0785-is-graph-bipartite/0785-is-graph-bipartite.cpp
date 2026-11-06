class Solution {
public:
    bool dfs(int node, int color, vector<int>& vis, 
                vector<int>& colorArr, vector<vector<int>>& graph) {
        vis[node] = true;
        colorArr[node] = color;
        color = !color;

        for(auto it : graph[node]) {
            if(!vis[it]) {
                if(!dfs(it, color, vis, colorArr, graph)) {
                    return false;
                }
            }
            else if(colorArr[it] == colorArr[node]) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color = 0;

        vector<int> colorArr(n, -1);
        vector<int> vis(n, false);

        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                if(!dfs(i, color, vis, colorArr, graph)) {
                    return false;
                }
            }
        }

        return true;
    }
};