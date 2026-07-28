class Solution {
public:
    using P = pair<int, pair<int,int>>;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        queue<P> q;
        q.push({0, {0, src}});

        while(!q.empty()) { 
            auto cell = q.front();
            q.pop();

            int stops = cell.first;
            int cost = cell.second.first;
            int node = cell.second.second;

            if(stops > k) continue;

            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;

                if(cost + edgeWt < dist[adjNode] &&
                   stops <= k) {

                    dist[adjNode] = cost + edgeWt;
                    q.push({stops + 1,
                            {cost + edgeWt, adjNode}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};