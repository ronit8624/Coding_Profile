class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, int color,
             vector<int>& colorArr, vector<bool>& vis) {
        vis[node] = true;
        colorArr[node] = color;
        color = !color;

        for(auto it : graph[node]) {
            if(!vis[it]) {
                if(!dfs(it, graph, color, colorArr, vis))
                    return false;
            }
            else {
                if(colorArr[it] == colorArr[node]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int color = 0;
        vector<int> colorArr(graph.size());
        vector<bool> vis(graph.size(), false);
        
        for(int i = 0; i < graph.size(); i++) {

            if(!vis[i]) {

                if(!dfs(i, graph, 0, colorArr, vis))
                    return false;
            }
        }

        return true;
    }
};