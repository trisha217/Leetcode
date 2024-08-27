class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& adj, vector<int>& vis, int node,
             int& orient) {
        vis[node] = 1;
        for (auto [nei, direction] : adj[node]) {
            if (!vis[nei]) {
                // If direction is 1, it means the edge was originally directed
                // from node to neighbor
                //but we need to flip it(neighbour to node)
                if (direction == 1) {
                    orient++;
                }
                dfs(adj, vis, nei, orient);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        int ans =0;
        vector<int> vis(n,0);
        vector<vector<pair<int, int>>> adj(n);
        for(auto it: connections){
            adj[it[0]].emplace_back(it[1], 1); // 1 means original direction
            adj[it[1]].emplace_back(it[0], 0); 
        }
        dfs(adj, vis, 0, ans);
        return ans;
    }
};