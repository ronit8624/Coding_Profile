class Solution {
public:
    void dfs(int node, vector<vector<int>>& rooms, vector<bool>& vis) {
        vis[node] = true;

        for(int i = 0; i < rooms[node].size(); i++) {
            int nextRoom = rooms[node][i];

            if(!vis[nextRoom]) {
                dfs(nextRoom, rooms, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);

        dfs(0, rooms, vis);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) return false;
        }

        return true;
    }
};