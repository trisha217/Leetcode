class Solution {
public:
    void dfs(int node,vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjLs[n]; 
        // to change adjacency matrix to list 
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                // self nodes are not considered
                if(isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }
        vector<int> vis(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjLs,vis);
            }
        }
        return cnt;
    }
};