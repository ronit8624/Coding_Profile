class DisjointSet {
private:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i=0;i<=n;i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if(node == parent[node]) 
            return node;
        
        return parent[node] = findUParent(parent[node]);
    }

    bool find(int u, int v) {
        return (findUParent(u) == findUParent(v));
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
       int ulp_u = findUParent(u);
       int ulp_v = findUParent(v);

       if(ulp_u == ulp_v) return;

       if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
       }
       else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
       }
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for(auto it : edges) {
            int u = it[0];
            int v = it[1];

            if(ds.find(u, v)) {
                return {u, v};
            }

            ds.unionBySize(u, v);
        }

        return {};
    }
};