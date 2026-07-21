class DisjointSet {
private:
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i=0;i<n;i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    bool find(int u, int v) {
        return findPar(u) == findPar(v);
    }

    void unionBySize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);
        
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            ds.unionBySize(u, v);
        }

        if(ds.findPar(source) == ds.findPar(destination)) return true;
        return false;
    }
};