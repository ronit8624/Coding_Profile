class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path,
             vector<vector<int>>& ans) {

        path.push_back(node);

        if(node == graph.size() - 1) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for(auto it : graph[node]) {
            dfs(it, graph, path, ans);
        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(0, graph, path, ans);
        return ans;
    }
};