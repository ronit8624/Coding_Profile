class Solution {
public:
    vector<int> topoSort(vector<int> adj[], int V) {
        vector<int> indegree(V);
        queue<int> q;
        vector<int> ans;

        for(int i=0;i<V;i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }

        for(int i=0;i<V;i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(auto it : adj[node]) {
                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return ans;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(auto it : prerequisites) {
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        vector<int> ans = topoSort(adj, numCourses);

        if(ans.size() != numCourses) return {};
        return ans;
    }
};