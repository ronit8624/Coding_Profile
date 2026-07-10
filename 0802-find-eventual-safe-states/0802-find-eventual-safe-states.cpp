class Solution {
public:
    vector<int> topoSort(vector<int> adj[], int N) {
        vector<int> indegree(N);
        vector<int> ans;
        queue<int> q;

        for(int i=0;i<N;i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }

        for(int i=0;i<N;i++) {
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

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> adj[N];
        
        for(int i=0;i<N;i++) {
            for(auto it : graph[i]) {
                adj[it].push_back(i);
            }
        }

        vector<int> ans = topoSort(adj, N);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};